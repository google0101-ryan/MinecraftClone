#include <net/minecraft/item/ItemGroup.hpp>

ItemGroup* ItemGroup::GROUPS[12] = {nullptr};
ItemGroup* ItemGroup::BUILDING_BLOCKS = (new ItemGroup(0, "buildingBlocks"))->setName("building_blocks");