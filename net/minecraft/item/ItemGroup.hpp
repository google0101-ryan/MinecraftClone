#pragma once

#include <string>

class ItemGroup
{
private:
    int index;
    std::string id;
    std::string name;
    std::string texture = "items.png";
    bool scrollbar = true;
    bool renderName = true;
public:
    static ItemGroup* GROUPS[12];
    static ItemGroup* BUILDING_BLOCKS;

    ItemGroup(int index, std::string id)
    {
        this->index = index;
        this->id = id;
        GROUPS[index] = this;
    }

    ItemGroup* setTexture(std::string tex)
    {
        this->texture = tex;
        return this;
    }

    ItemGroup* setName(std::string name)
    {
        this->name = name;
        return this;
    }
};