#include <net/minecraft/block/AbstractBlock.hpp>

AbstractBlock::Settings* AbstractBlock::Settings::noCollision()
{
    collidable = false;
    opaque = false;
    return this;
}

AbstractBlock::Settings* AbstractBlock::Settings::nonOpaque()
{
    opaque = false;
    return this;
}

AbstractBlock::Settings* AbstractBlock::Settings::setSlipperiness(float slippy)
{
    slipperiness = slippy;
    return this;
}

AbstractBlock::Settings* AbstractBlock::Settings::velocityMul(float velocity)
{
    velocityMultiplier = velocity;
    return this;
}

AbstractBlock::Settings* AbstractBlock::Settings::strength(float hard, float resist)
{
    this->hardness = hard;
    this->resistance = resist;
    return this;
}

AbstractBlock::Settings* AbstractBlock::Settings::strength(float strgth)
{
    strength(strgth, strgth);
    return this;
}

AbstractBlock::Settings* AbstractBlock::Settings::requiresTool()
{
    toolRequired = true;
    return this;
}

AbstractBlock::Settings* AbstractBlock::Settings::dropsNothing()
{
    this->lootTableId = new Identifier("minecraft:recipes/empty");
    return this;
}

AbstractBlock::Settings* AbstractBlock::Settings::air()
{
    this->isAir = true;
    return this;
}