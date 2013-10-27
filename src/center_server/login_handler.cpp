#include <common.h>
#include <network_common.h>
#include <protobuf.h>
#include <packet.h>
#include "game_session.h"
#include "game_database_session.h"
#include "opcodes.h"
#include "game_util.h"
#include "player_pool.h"

void GameSession::user_login_handler(const NetworkMessage& message)
{
    Protocol::C2SLoginReq request;
    message.parse(request);

    debug_log("[User Login] -> (Username='%s', Password='%s')", request.email().c_str(), request.password().c_str());

    //�ж������ʺŷǷ�
    if (GameUtil::checkEmailValid(request.email()) == false)
    {
        Protocol::S2CLoginRsp login_response;
        login_response.set_login_result(false);
        login_response.set_failed_reason("�����ʺŷǷ���");
        send_message<Protocol::S2CLoginRsp>(Opcodes::S2CLoginRsp, login_response);

        debug_log("login email '%s' invalid, login failed.", request.email().c_str());
        return;
    }

    //�ж�����hash�Ƿ�
    if (GameUtil::checkPasswordHashValid(request.password()) == false)
    {
        Protocol::S2CLoginRsp login_response;
        login_response.set_login_result(false);
        login_response.set_failed_reason("����Ƿ���");
        send_message<Protocol::S2CLoginRsp>(Opcodes::S2CLoginRsp, login_response);

        debug_log("login password '%s' not a legal MD5 hash, login failed.", request.password().c_str());
        return;
    }

    //����¼�ʺ��Ƿ����
    Protocol::S2CLoginRsp login_response;
    bool user_exists = GameDatabaseSession::getInstance().checkUserExists(request.email());
    if (user_exists == true)
    {
        debug_log("User ('%s') not exists.", request.email().c_str());

        //��֤�ʺź������Ƿ�ƥ��
        bool auth_result = GameDatabaseSession::getInstance().userAuth(request.email(), request.password());
        login_response.set_login_result(auth_result);

        if (auth_result == false)
        {
            //�ʺź����벻ƥ��
            debug_log("email('%s') and password('%s') not match.", request.email().c_str(), request.password().c_str());
            login_response.set_failed_reason("�ʺź����벻ƥ�䡣");
        }
        else
        {
            //uint64 guid = GameUtil::toUniqueId(request.email());
            //login_response.set_player_id(guid);

            // Todo : load the player data if specify player cache exists

            Player* player = PlayerPool::getInstance().acquire();

            //��֤�ɹ�
            debug_log("email('%s') and password('%s') matched, authentication success.", request.email().c_str(), request.password().c_str());
        }
    }
    else
    {
        //�û�������
        login_response.set_login_result(false);
        login_response.set_failed_reason("�û������ڡ�");
    }

    send_message<Protocol::S2CLoginRsp>(Opcodes::S2CLoginRsp, login_response);
}

void GameSession::user_register_handler(const NetworkMessage& message)
{
    Protocol::C2SRegisterReq request;
    message.parse(request);

    debug_log("[User Register] -> (Username='%s', Nickname='%s')", request.email().c_str(), request.nickname().c_str());

    //�ж������ʺŷǷ�
    if (GameUtil::checkEmailValid(request.email()) == false)
    {
        Protocol::S2CRegisterRsp register_respone;
        register_respone.set_register_result(false);
        register_respone.set_failed_reason("�����ʺŷǷ���");
        send_message<Protocol::S2CRegisterRsp>(Opcodes::S2CRegisterRsp, register_respone);

        debug_log("register email '%s' invalid, register failed.", request.email().c_str());
        return;
    }

    //�ж�����hash�Ƿ�
    if (GameUtil::checkPasswordHashValid(request.password()) == false)
    {
        Protocol::S2CRegisterRsp register_respone;
        register_respone.set_register_result(false);
        register_respone.set_failed_reason("����Ƿ���");
        send_message<Protocol::S2CRegisterRsp>(Opcodes::S2CRegisterRsp, register_respone);

        debug_log("register password '%s' not a legal MD5 hash, register failed.", request.password().c_str());
        return;
    }

    //ע���˺��Ƿ��Ѵ���
    bool user_exist = GameDatabaseSession::getInstance().checkUserExists(request.email());
    if (user_exist == true)
    {
        Protocol::S2CRegisterRsp register_respone;
        register_respone.set_register_result(false);
        register_respone.set_failed_reason("ע��ʧ�ܣ��������ʺ��Ѵ��ڡ�");
        send_message<Protocol::S2CRegisterRsp>(Opcodes::S2CRegisterRsp, register_respone);

        debug_log("register user '%s' exists, register failed.", request.email().c_str());
        return;
    }
    
    //ע���ǳ��Ƿ��Ѵ���
    bool nickname_exist = GameDatabaseSession::getInstance().checkNicknameExists(request.nickname());
    if (nickname_exist == true)
    {
        Protocol::S2CRegisterRsp register_respone;
        register_respone.set_register_result(false);
        register_respone.set_failed_reason("ע��ʧ�ܣ����ǳ��Ѵ��ڡ�");
        send_message<Protocol::S2CRegisterRsp>(Opcodes::S2CRegisterRsp, register_respone);

        debug_log("register nickname '%s' exists, register failed.", request.nickname().c_str());
        std::wcout << request.nickname().c_str() << std::endl;
        return;
    }

    GameDatabaseSession::getInstance().insertNewUserRecord(
        GameUtil::toUniqueId(request.email()),
        request.email(),
        request.password(),
        (uint8)request.gender(),
        request.nickname(),
        connection()->getPeerAddress().host(),
        Poco::Timestamp().epochTime());

    Protocol::S2CRegisterRsp register_respone;
    register_respone.set_register_result(true);
    register_respone.set_failed_reason("");

    send_message<Protocol::S2CRegisterRsp>(Opcodes::S2CRegisterRsp, register_respone);

    debug_log("register success.");
}