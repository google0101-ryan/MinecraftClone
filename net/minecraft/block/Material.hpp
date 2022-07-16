#pragma once

class Material
{
private:
    bool blocksLight;
    bool blocksMovement;
    bool burnable;
    bool liquid;
    bool replaceable; // Grass, flowers, etc.
    bool solid;

    class Builder
    {
    private:
        bool blocksMovement = true;
        bool burnable;
        bool liquid;
        bool replaceable;
        bool solid = true;
        bool blocksLight = true;
    public:
        Material* build() {return new Material(liquid, solid, blocksMovement, blocksLight, burnable, replaceable);}

        Builder* allowsMovement() {blocksMovement = false; return this;}
        Builder* lightPassesThrough() {blocksLight = false; return this;}
        Builder* notSolid() {solid = false;  return this; return this;}
        Builder* replace() {replaceable = true; return this;}
    };
public:
    Material(bool liquid, bool solid, bool blocksMovement, bool blocksLight, bool burnable, bool replacable)
    {
        this->liquid = liquid;
        this->solid = solid;
        this->blocksLight = blocksLight;
        this->blocksMovement = blocksMovement;
        this->burnable = burnable;
        this->replaceable = replacable;
    }

    static Material* SOIL;
    static Material* STONE;
    static Material* AIR;
};