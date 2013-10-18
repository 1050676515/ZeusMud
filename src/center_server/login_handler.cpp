#include <common.h>
#include <network_common.h>
#include <protobuf.h>
#include <packet.h>
#include "game_session.h"
#include "game_database_session.h"
#include "opcodes.h"
#include "game_util.h"

void GameSession::user_login_handler(const NetworkMessage& message)
{
    Protocol::C2SLoginReq request;
    message.parse(request);

    printf("[User Login] -> (Username='%s', Password='%s')", request.email().c_str(), request.password().c_str());

    //�ж������ʺŷǷ�
    if (GameUtil::getInstance().checkEmailValid(request.email()) == false)
    {
        printf("register email '%s' invalid, register failed.", request.email().c_str());
        return;
    }

    //�ж�����hash�Ƿ�
    if (GameUtil::getInstance().checkPasswordHashValid(request.password()) == false)
    {
        printf("register password '%s' not a legal MD5 hash, register failed.", request.email().c_str());
        return;
    }

    Protocol::S2CLoginRsp login_response;
    bool exists = GameDatabaseSession::getInstance().checkUserExists(request.email());
    login_response.set_login_result(exists);
    login_response.set_failed_reason(exists == true ? "" : "�û������ڡ�");

    send_message<Protocol::S2CLoginRsp>(Opcodes::S2CLoginRsp, login_response);
}

void GameSession::user_register_handler(const NetworkMessage& message)
{
    Protocol::C2SRegisterReq request;
    message.parse(request);

    printf("[User Register] -> (Username='%s', Nickname='%s')", request.email().c_str(), request.nickname().c_str());

    //�ж������ʺŷǷ�
    if (GameUtil::getInstance().checkEmailValid(request.email()) == false)
    {
        printf("register email '%s' invalid, register failed.", request.email().c_str());
        return;
    }

    //�ж�����hash�Ƿ�
    if (GameUtil::getInstance().checkPasswordHashValid(request.password()) == false)
    {
        printf("register password '%s' not a legal MD5 hash, register failed.", request.email().c_str());
        return;
    }

    Protocol::S2CRegisterRsp register_response;
    bool exists = GameDatabaseSession::getInstance().checkUserExists(request.email());
    if (exists == true)
    {
        register_response.set_register_result(false);
        register_response.set_failed_reason("ע��ʧ�ܣ����û��Ѵ��ڣ��뻻�������������ʺš�");
    }
    else
    {
        GameDatabaseSession::getInstance().insertNewUserRecord(
            GameUtil::getInstance().toUniqueId(request.email()),
            request.email(),
            request.password(),
            (uint8)request.gender(),
            request.nickname(),
            connection()->getPeerAddress().host(),
            Poco::Timestamp().epochTime());

        register_response.set_register_result(true);
        register_response.set_failed_reason("");
    }

    send_message<Protocol::S2CRegisterRsp>(Opcodes::S2CRegisterRsp, register_response);
}