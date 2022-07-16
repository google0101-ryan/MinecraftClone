#include <net/minecraft/util/Identifier.hpp>

Identifier::Identifier(std::string id)
{
    auto pos = id.find(":");
    if (pos == std::string::npos)
    {
        printf("ERROR: net.minecraft.util.Identifier: string %s does not contain ':'\n", id.c_str());
        exit(1);
    }

    namesp = id.substr(0, pos);
    path = id.substr(pos + 1);

    printf("[INFO]: Registered new identifier %s:%s\n", namesp.c_str(), path.c_str());
}