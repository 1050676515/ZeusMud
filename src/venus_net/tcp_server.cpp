#include "inet_address.h"
#include "tcp_server.h"
#include "network_common.h"
#include "tcp_connection.h"

TcpServer::TcpServer(const InetAddress& listenAddress, IOService& service, uint32_t threadNums)
    : _io_service(service),
    _acceptor(listenAddress, service, threadNums),
    _started(false),
    _signals(service.service())
{
    debug_log("Server starting ...");

    //��Ӳ�׽�ź�
    _signals.add(SIGINT);
    _signals.add(SIGTERM);

#if defined(SIGQUIT)
    _signals.add(SIGQUIT);
#endif
    _signals.async_wait(std::bind(&TcpServer::stop, this));

    _acceptor.registerAcceptedEvent(BIND_EVENT_HANDLER(&TcpServer::acceptedHandler, this));
}

TcpServer::~TcpServer()
{
    _signals.clear();
}

void TcpServer::start()
{
    if (!_started)
    {
        _started = true;
    }
    else
    {
        stop();
    }

    _acceptor.listen();
    _acceptor.startAccept();
}

void TcpServer::stop()
{
    //stop acceptor
    _acceptor.stopAccept();

    //close all alived connections
    // ...
    debug_log("Server stopped.");
}

void TcpServer::registerNewConnectionEvent(const NewConnectionEvent& event)
{
    _newConnectionEvent = event;
}

void TcpServer::registerDataWriteFinishedEvent(const DataWriteFinishedEvent& event)
{
    _dataWriteFinishedEvent = event;
}

void TcpServer::registerDataReadEvent(const DataReadEvent& event)
{
    _dataReadEvent = event;
}

void TcpServer::registerConnectionClosedEvent(const ConnectionClosedEvent& event)
{
    _connectionClosedEvent = event;
}

void TcpServer::acceptedHandler(const TcpConnectionPtr& connection, const EventArgs& args)
{
    debug_log("thread id = %d", std::this_thread::get_id());

    //callbacks
    connection->registerDataWriteFinishedEvent(_dataWriteFinishedEvent);
    connection->registerDataReadEvent(_dataReadEvent);
    connection->registerConnectionClosedEvent(_connectionClosedEvent);

    if (_newConnectionEvent)
    {
        _newConnectionEvent(connection, NewConnectionEventArgs(connection->getPeerAddress()));
    }
}