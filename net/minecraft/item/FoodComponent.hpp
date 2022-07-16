#pragma once

class FoodComponent
{
private:
    int hunger;
    float saturationModifier;
    bool meat;
    bool alwaysEdible;
    bool snack;
public:
    FoodComponent(int hunger, float saturationModifier, bool meat, bool alwaysEdible, bool snack)
    {
        this->hunger = hunger;
        this->saturationModifier = saturationModifier;
        this->meat = meat;
        this->alwaysEdible = alwaysEdible;
        this->snack = snack;
    }

    int getHunger()
    {
        return hunger;
    }

    class Builder
    {
    private:
        int hunger;
        float saturation;
        bool meat;
        bool alwaysEdible;
        bool snack;
    public:
        Builder* setHunger(int hunger)
        {
            this->hunger = hunger;
            return this;
        }
    };
};