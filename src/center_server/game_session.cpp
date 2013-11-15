#include "game_session.h"
#include "game_session_manager.h"
#include "player.h"

GameSession::GameSession(const uint64& session_id)
    : NetworkSession(session_id)
{

}

GameSession::~GameSession()
{
}


bool GameSession::init()
{
    return true;
}

void GameSession::destroy()
{
    stopHeartbeatCheck();
}

void GameSession::heartbeat_handler(const NetworkMessage& message)
{
	std::time_t now = Poco::Timestamp().epochTime();
	_heartbeat.last_heartbeat_time = now;
}

Player* GameSession::getPlayer()
{
    return _player;
}

void GameSession::attackPlayerPtr(Player* player)
{
    _player = player;
}

void GameSession::onHeartbeatCheck(Poco::Timer& timer)
{
    info_log("[%ull] - > Check Heartbeat", _player->guid());

    // ����������
    // ��������������ʱ����40��һ�����ڣ�������ǰ�����2�룬Ҳ����˵��58~62��֮�䱨���ǺϷ��ġ�
    // ������ڷ�Χ�ڱ����������Ϊһ���쳣������ָ���������ߵ����ӡ�

    std::time_t now = Poco::Timestamp().epochTime();
    int64 interval = now - _heartbeat.last_heartbeat_time;
    int32 up_deviation_value = SessionHeartbeat::HEARTBEAT_TIME + SessionHeartbeat::HEARTBEAT_DEVIATION_VALUE;
    int32 down_deviation_value = SessionHeartbeat::HEARTBEAT_TIME - SessionHeartbeat::HEARTBEAT_DEVIATION_VALUE;

    if (interval > up_deviation_value || interval < down_deviation_value)
    {
        ++_heartbeat.failed_count;
        warning_log("Player %ull unormal heartbeat happened, failed_count = %d", _player->guid(), _heartbeat.failed_count);

        //���������������ʱ���쳣�����ж�Ϊ���粻�ȶ����ߵ�
        if (_heartbeat.failed_count >= 3)
        {
            debug_log("Player %ull failed heartbeat at the limit, close session.", _player->guid());
            GameSessionManager::getInstance().destroySession(this);
        }
    }
    else
    {
        _heartbeat.failed_count = 0;
    }
}

void GameSession::startHeartbeatCheck(long interval/* = 10000*/)
{
    //��ʼ������ʱ��
    _heartbeat.last_heartbeat_time = Poco::Timestamp().epochTime();

    //��ʼ�������
    _heartbeat_checker.setStartInterval(interval);
    _heartbeat_checker.setPeriodicInterval(interval);

    Poco::TimerCallback<GameSession> heartbeat_check_callback(*this, &GameSession::onHeartbeatCheck);  
    _heartbeat_checker.start(heartbeat_check_callback);
}

void GameSession::stopHeartbeatCheck()
{
    _heartbeat_checker.stop();
}
