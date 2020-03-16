#include <iostream>
#include <src/util/registry.hpp>
#include <src/core/factories.hpp>
#include <core/set_interval.hpp>
#include <src/sys/update.hpp>
#include <mosquitopp_client/lib/include/mqtt.h>

int main()
{
    Registry reg;
    makeBrooksPTI(reg, 1);

    mosqpp::lib_init();
    mqtt_client iot_client("SM1PRO_ENTT", "127.0.0.1", 60000, [&reg](std::string const &message)
    {
        update(reg);
    });
    iot_client.start_loop();

    bool stopping{false};
    while(!stopping)
    {
        update(reg);
        std::string command;
        std::cin >> command;
        if (command == "stop")
        {
            stopping = true;
        }
        else
        {
            std::cout << command << std::endl;
        }
    }


    mosqpp::lib_cleanup();

    return 0;
}