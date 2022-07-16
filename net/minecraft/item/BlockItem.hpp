#pragma once

#include <net/minecraft/item/Item.hpp>

class BlockItem : public Item
{
private:
    Block* block;
public:
    BlockItem(Block* b, Item::Settings* settings)
    : Item(settings)
    {
        block = b;
    }
};