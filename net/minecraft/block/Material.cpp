#include <net/minecraft/block/Material.hpp>

Material* Material::SOIL = (new Material::Builder())->build();
Material* Material::STONE = (new Material::Builder())->build();
Material* Material::AIR = (new Material::Builder())->allowsMovement()->lightPassesThrough()->notSolid()->replace()->build();