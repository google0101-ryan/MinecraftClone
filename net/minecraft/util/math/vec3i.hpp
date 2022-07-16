#pragma once

class Vec3i
{
private:
    int x;
    int y;
    int z;
public:
    Vec3i(int x, int y, int z)
    : x(x), y(y), z(z) {}

    static Vec3i* ZERO;
};