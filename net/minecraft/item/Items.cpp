#include <net/minecraft/item/Items.hpp>
#include <net/minecraft/block/Blocks.hpp>

Item* Items::DIRT = Registry::RegisterItem("dirt", new BlockItem(Blocks::DIRT, Item::Settings::of()->setGroup(ItemGroup::BUILDING_BLOCKS)));