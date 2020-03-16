#ifndef SM1PRO_ENTT_FACTORIES_HPP
#define SM1PRO_ENTT_FACTORIES_HPP

#include <src/util/registry.hpp>
#include <src/comp/sensor.hpp>
#include <src/comp/sensor_type.hpp>
#include <src/comp/sensor_name.hpp>
#include <src/comp/sensor_brand.hpp>
#include <src/comp/data_type.hpp>
#include <src/sys/update.hpp>

inline Entity makeSensor(Registry &reg)
{
    const Entity e = reg.create();
    reg.assign<Sensor>(e);
    return e;
}

inline Entity makeBrooksPTI(Registry &reg, size_t id)
{
    const Entity e = makeSensor(reg);
    reg.assign<brooks>(e);
    reg.assign<pti>(e);
    reg.assign<pressure>(e);
    reg.assign<sensor_name>(e, std::to_string(id));
    reg.assign<numeric_value>(e, 0.0);
    return e;
}

#endif //SM1PRO_ENTT_FACTORIES_HPP
