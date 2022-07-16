#pragma once

#include <string>

class Identifier
{
private: 
    std::string namesp; // Namespace, like minecraft:
    std::string path; // Remainder, like dirt_block
public:
    Identifier(std::string id);
    Identifier(std::string namesp, std::string rest) {this->namesp = namesp; this->path = rest;}

    std::string getNamespace();
    std::string getPath();
};