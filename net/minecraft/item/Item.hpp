#pragma once

#include <net/minecraft/item/ItemGroup.hpp>
#include <net/minecraft/item/FoodComponent.hpp>
#include <net/minecraft/util/registry/Registry.hpp>
#include <net/minecraft/block/Block.hpp>
#include <net/minecraft/block/Blocks.hpp>
#include <unordered_map>

class Item
{
private:
    const int DEFAULT_MAX_COUNT = 64;
    int maxCount;
    int maxDamage;
    bool fireproof;
    FoodComponent* foodComponent;
protected:
    ItemGroup* group;
public:
    static std::unordered_map<Block*, Item*> BLOCK_ITEMS;
    
    static Item* fromBlock(Block* block)
    {
        return BLOCK_ITEMS[block];
    }

    class Settings
    {
        friend class Item;
    private:
        int maxCount = 64;
        int maxDamage;
        ItemGroup* group;
        FoodComponent* foodComponent;
        bool fireproof;
    public:
        static Settings* of()
        {
            return new Settings();
        }
        Settings* food(FoodComponent* foodComponent)
        {
            this->foodComponent = foodComponent;
            return this;
        }
        Settings* setMaxCount(int maxCount)
        {
            if (this->maxDamage > 0)
            {
                printf("[ERROR]: Cannot have max damage AND stack\n");
                exit(1);
            }
            this->maxCount = maxCount;
        }
        Settings* setMaxDamageIfAbsent(int maxDamage)
        {
            return this->maxDamage == 0 ? this->setMaxDamage(maxDamage) : this;
        }
        Settings* setMaxDamage(int maxDamage)
        {
            this->maxDamage = maxDamage;
            this->maxCount = 1;
            return this;
        }
        Settings* setGroup(ItemGroup* group)
        {
            this->group = group;
            return this;
        }
        Settings* setFireproof()
        {
            fireproof = true;
            return this;
        }
    };

    Item(Settings* settings)
    {
        this->maxCount = settings->maxCount;
        this->maxDamage = settings->maxDamage;
        this->group = settings->group;
        this->foodComponent = settings->foodComponent;
        this->fireproof = settings->fireproof;
    }
};