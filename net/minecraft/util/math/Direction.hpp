#pragma once

#include <string>

#include <net/minecraft/util/math/vec3i.hpp>

class Direction
{
private:
    class AxisDirection
    {
    private:
        int offset;
        std::string description;

    public:
        AxisDirection(int offset, std::string desc)
        : offset(offset), description(desc) {}

        static AxisDirection* POSITIVE;
        static AxisDirection* NEGATIVE;
    };

    int id;
    int idOpposite;
    int idHorizontal;
    std::string name;
    AxisDirection* direction;
    Vec3i* vector;
    Direction(int id, int idOpposite, int idHorizontal, std::string name, AxisDirection* dir, Vec3i* vec)
    : id(id), idOpposite(idOpposite), idHorizontal(idHorizontal), name(name), direction(dir), vector(vec) {}
public:
    static Direction* DOWN;
    static Direction* UP;
    static Direction* NORTH;
    static Direction* SOUTH;
    static Direction* WEST;
    static Direction* EAST;
};