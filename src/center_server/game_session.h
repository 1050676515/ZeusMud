#ifndef __GAME_SESSION_H__
#define __GAME_SESSION_H__

#include "network_session.h"

class Player;
class GameSession
    : public NetworkSession
{
public:
    GameSession(const uint64& session_id);
    virtual ~GameSession();

public:
    //��¼ģ��
    void user_login_handler(const NetworkMessage& message);
    void user_register_handler(const NetworkMessage& message);

    //�������ģ��
    void get_player_profile_handler(const NetworkMessage& message);

private:
    void attackPlayerPtr(Player* player);

private:
    Player* _player;
};

#endif