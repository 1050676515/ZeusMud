#ifndef __GAME_DATABASE_SESSION_H__
#define __GAME_DATABASE_SESSION_H__

#include <singleton.h>
#include <Poco/Data/Common.h>
#include <Poco/Data/SQLite/Connector.h>
#include <Poco/Data/RecordSet.h>
#include <Poco/Data/SessionFactory.h>
#include "db_user.h"

class GameDatabaseSession
    : public Venus::Singleton<GameDatabaseSession>
{
public:
    GameDatabaseSession();
    ~GameDatabaseSession();

public:
    //====================================================================
    // ��¼ϵͳ
    //====================================================================

    //������ݿ���һ���û��Ƿ����
    bool checkUserExists(const std::string& email);

    //�����µ��û���¼
    void insertNewUserRecord(
        uint64 user_id, 
        const std::string& email,
        const std::string& password,
        uint8 gender,
        const std::string& nickname,
        const std::string& register_ip,
        uint64 register_timestamp
    );

private:
    Poco::Data::Session _db_session;
    Poco::Data::Statement _db_stmt;
};

#endif