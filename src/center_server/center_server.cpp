// center_server.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "game_service_deamon.h"

int main(int argc, char* argv[])
{
    try
    {
        IOService service;
        GameServiceDeamon serviceEntry("ZeusMud_Service", service);
        serviceEntry.start(36911, 4);
    }
    catch (...)
    {
        std::cout << "An unknown exception occurred." << std::endl;
    }

    system("pause");
	return 0;
}

