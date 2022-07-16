#include <net/minecraft/util/math/Direction.hpp>

Direction::AxisDirection* Direction::AxisDirection::POSITIVE = new Direction::AxisDirection(1, "Towards positive");
Direction::AxisDirection* Direction::AxisDirection::NEGATIVE = new Direction::AxisDirection(-1, "Towards negative");

Direction* Direction::DOWN = new Direction(0, 1, -1, "down", Direction::AxisDirection::NEGATIVE, new Vec3i(0, -1, 0));
Direction* Direction::UP = new Direction(1, 0, -1, "up", Direction::AxisDirection::POSITIVE, new Vec3i(0, 1, 0));
Direction* Direction::NORTH = new Direction(2, 3, 2, "north", Direction::AxisDirection::NEGATIVE, new Vec3i(0, 0, -1));
Direction* Direction::SOUTH = new Direction(3, 2, 0, "south", Direction::AxisDirection::POSITIVE, new Vec3i(0, 0, 1));
Direction* Direction::WEST = new Direction(4, 5, 1, "west", Direction::AxisDirection::NEGATIVE, new Vec3i(-1, 0, 0));
Direction* Direction::EAST = new Direction(5, 4, 3, "east", Direction::AxisDirection::POSITIVE, new Vec3i(1, 0, 0));
