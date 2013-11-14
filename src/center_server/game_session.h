#ifndef __GAME_SESSION_H__
#define __GAME_SESSION_H__

#include "network_session.h"

class Player;
class GameSession
    : public NetworkSession
{
	struct SessionHeartbeat
	{
		static const int32 HEARTBEAT_TIME = 60000;           //������ʱʱ�䣨60�룩
		static const int32 HEARTBEAT_DEVIATION_VALUE = 2000; //�������ֵ��2�룩

		SessionHeartbeat() 
		{
			cleanup();
		}

		void cleanup()
		{
			last_heartbeat_time = 0;
			failed_count = 0;
		}

		int64 last_heartbeat_time;
		int32 failed_count;
	};

public:
    GameSession(const uint64& session_id);
    virtual ~GameSession();

public:
    Player* getPlayer();

public:
	//����
	void heartbeat_handler(const NetworkMessage& message);

    //��¼ģ��
    void user_login_handler(const NetworkMessage& message);
    void user_register_handler(const NetworkMessage& message);

    //�������ģ��
    void get_player_profile_handler(const NetworkMessage& message);

    //����ģ��
    void chat_message_handler(const NetworkMessage& message);

    //����ģ��
    void room_create_handler(const NetworkMessage& message);
    void get_room_list_handler(const NetworkMessage& message);
    void broadcast_room_add(uint32 id, const std::string& roomName, bool isPublic);
private:
    void attackPlayerPtr(Player* player);

private:
    Player* _player;
	SessionHeartbeat _heartbeat;
};

#endif