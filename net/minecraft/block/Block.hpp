#pragma once

#include <net/minecraft/block/AbstractBlock.hpp>

class Block : public AbstractBlock
{
public:
    Block(AbstractBlock::Settings* settings)
    : AbstractBlock(settings) {}
};