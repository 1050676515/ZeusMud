#ifndef __NETWORK_MANAGER_H__
#define __NETWORK_MANAGER_H__

#include <network_common.h>
#include <singleton.h>
#include <io_service.h>
#include "game_session.h"

typedef std::function<void (const GameSession* session)> OnSessionCreated;
typedef std::function<void (const GameSession* session, NetworkMessage* message)> OnSessionMessage;
typedef std::function<void (const GameSession* session)> OnSessionClosing;

class IODataEventHandler
{
public:
    virtual ~IODataEventHandler() {}

    virtual void newConnectionEvent(const TcpConnectionPtr& connection, const NewConnectionEventArgs& args) = 0;
    virtual void dataWriteFinishedEvent(const TcpConnectionPtr& connection, const DataWriteFinishedEventArgs& args) = 0;
    virtual void dataReadEvent(const TcpConnectionPtr& connection, const DataReadEventArgs& args) = 0;
    virtual void connectionClosedEvent(const TcpConnectionPtr& connection, const EventArgs& args) = 0;
};

class IODataDispatcher
{
public:
	OnSessionCreated onSessionCreated;
	OnSessionMessage onSessionMessage;
	OnSessionClosing onSessionClosing;
};

class TcpServer;
class GameIODataEventHandler;
class NetworkProxy
    : public Venus::Singleton<NetworkProxy>
{
public:
    NetworkProxy();
    virtual ~NetworkProxy();

public:
    // ��ʼ������
    bool init(IOService& service, GameIODataEventHandler* event_handler, uint16 listen_port, uint32 io_thread_numbers);

    // �ͷ�����
    void destroy();

    // �����ر�һ���ϲ�����
    // ע��ͨ���������øýӿڹر�����ʱ���ᴥ�����ϲ��ConnectionClosed�¼����ͷ���Ϸ��Դ����
    void close_connection(const TcpConnectionPtr& connection);

private:
	// IO�¼�ע��
	void registerSessionCreatedEvent(const NewConnectionEvent& event);
	void registerDataWriteFinishedEvent(const DataWriteFinishedEvent& event);
	void registerDataReadEvent(const DataReadEvent& event);
	void registerConnectionClosedEvent(const ConnectionClosedEvent& event);

    // �ڲ��¼�
    // �յ�����֮ǰ����NetworkProxy�ӹܣ�����һЩ���ӵĹ����Լ����չ����ٻص����ϲ�
    void __internalNewConnectionEvent(const TcpConnectionPtr& connection, const NewConnectionEventArgs& args);
    void __internalDataWriteFinishedEvent(const TcpConnectionPtr& connection, const DataWriteFinishedEventArgs& args);
	void __internalDataReadEvent(const TcpConnectionPtr& connection, const DataReadEventArgs& args);
	void __internalConnectionClosedEvent(const TcpConnectionPtr& connection, const EventArgs& args);

private:
    IODataDispatcher _dispatcher;
    GameIODataEventHandler* _event_handler;
    IOService* _service;
    TcpServer* _server;

    // ������������
    // - first  : session id
    // - second : TcpConnection
	adap_map<uint32, const TcpConnectionPtr*> _connections;
};

#endif