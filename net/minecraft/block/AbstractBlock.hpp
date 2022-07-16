#pragma once

#include <net/minecraft/util/Identifier.hpp>
#include <net/minecraft/util/math/Direction.hpp>
#include <net/minecraft/block/Material.hpp>

class Block;

class AbstractBlock
{
protected:
    bool collidable; // Can we collide with this block?
    bool dynamicBounds; // Can the block's bounds change?
    float jumpVelocityMultiplier; // Slime, Honey Block
    bool randomTicks; // Not sure what this is for
    float resistance; // Explosion resistance
    float slipperiness; // How long it takes to stop after the player stops
    float velocityMultiplier; // How fast this makes the player speed up
    Identifier* lootTableId; // The name of the loot table for the block
    //virtual Block* asBlock() = 0;
public:
    float getHardness();

    class Settings
    {
        friend class AbstractBlock;
    private:
        Material* material;
        bool collidable = true;
        float resistance;
        float hardness;
        bool toolRequired;
        bool randomTicks;
        float slipperiness = 0.6f;
        float velocityMultiplier =  1.0f;
        float jumpVelocityMultiplier = 1.0f;
        Identifier* lootTableId;
        bool opaque = true;
        bool isAir;
        bool dynamicBounds;
    public:
        Settings(Material* material) {this->material = material;}
        static Settings* of(Material* m) {return new Settings(m);}
        Settings* noCollision();
        Settings* nonOpaque();
        Settings* setSlipperiness(float slippy);
        Settings* velocityMul(float multiplier);
        Settings* jumpVelocityMul(float multiplier);
        Settings* strength(float hard, float resist);
        Settings* breakInstantly();
        Settings* strength(float hard);
        Settings* ticksRandomly();
        Settings* requiresTool();
        Settings* setHardness(float hard);
        Settings* setResistance(float resist);
        Settings* dropsNothing();
        Settings* air();
    };
protected:
    Settings* settings;
public:
    AbstractBlock(Settings* settings)
    {
        this->collidable = settings->collidable;
        this->lootTableId = settings->lootTableId;
        this->resistance = settings->resistance;
        this->randomTicks = settings->randomTicks;
        this->slipperiness = settings->slipperiness;
        this->velocityMultiplier = settings->velocityMultiplier;
        this->jumpVelocityMultiplier = settings->jumpVelocityMultiplier;
        this->dynamicBounds = settings->dynamicBounds;
        this->settings = settings;
    }
};