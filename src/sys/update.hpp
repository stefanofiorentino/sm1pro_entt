#ifndef SM1PRO_ENTT_UPDATE_HPP
#define SM1PRO_ENTT_UPDATE_HPP

#include <src/comp/sensor_type.hpp>
#include <src/comp/sensor_name.hpp>
#include <src/comp/data_type.hpp>
#include <src/comp/numeric_value.hpp>

void update(Registry &reg)
{
    auto view = reg.view<Sensor, sensor_type, sensor_name, data_type, numeric_value>();
    for (const Entity e : view)
    {
        auto const &s_type = view.get<sensor_type>(e).type;
        auto const &s_name = view.get<sensor_name>(e).name;
        auto const &d_type = view.get<data_type>(e).type;
        auto const &value = view.get<numeric_value>(e).value;

        std::cout << s_type << ", " << s_name << ", " << d_type << ", " << std::to_string(value) << std::endl;
    }

    auto brooks_pti_pressure_view = reg.view<Sensor, brooks, pti, pressure, numeric_value>();
    for (const Entity e : brooks_pti_pressure_view)
    {
        auto const &value = brooks_pti_pressure_view.get<numeric_value>(e).value;

        std::cout << "brooks, pti, pressure, " << std::to_string(value) << std::endl;
    }
}

#endif //SM1PRO_ENTT_UPDATE_HPP
