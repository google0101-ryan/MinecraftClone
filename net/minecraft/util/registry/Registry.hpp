#pragma once

#include <string>
#include <vector>
#include <tuple>

class Registry
{
private:
    static std::vector<std::pair<std::string, void*>> block_registry;
    static std::vector<std::pair<std::string, void*>> item_registry;
public:
    template<typename T>
    static T* RegisterBlock(std::string id, T* c)
    {
        block_registry.push_back(std::make_pair(id, (void*)c));
        return c;
    }

    template<typename T>
    static T* RegisterItem(std::string id, T* c)
    {
        item_registry.push_back(std::make_pair(id, (void*)c));
        return c;
    }

    template<typename T>
    static T* FindBlockByID(std::string id)
    {
        for (auto it : block_registry)
        {
            if (it.first == id)
            {
                return (T*)it.second;
            }
        }
        return nullptr;
    }
};