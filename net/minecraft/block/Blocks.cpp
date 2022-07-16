#include <net/minecraft/block/Blocks.hpp>
#include <net/minecraft/util/registry/Registry.hpp>

Block* Blocks::DIRT = Registry::RegisterBlock("dirt", new Block(AbstractBlock::Settings::of(Material::SOIL)->strength(0.5f)));
Block* Blocks::STONE = Registry::RegisterBlock("stone", new Block(AbstractBlock::Settings::of(Material::STONE)->requiresTool()->strength(1.5f, 6.0f)));
Block* Blocks::BEDROCK = Registry::RegisterBlock("bedrock", new Block(AbstractBlock::Settings::of(Material::STONE)->strength(-1.0f, 3600000.0f)->dropsNothing()));
Block* Blocks::AIR = Registry::RegisterBlock("air", new Block(AbstractBlock::Settings::of(Material::AIR)->noCollision()->dropsNothing()->air()));