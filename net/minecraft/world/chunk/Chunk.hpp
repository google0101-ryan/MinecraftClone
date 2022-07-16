#pragma once

#include <net/minecraft/block/Blocks.hpp>
#include <noise/noise.h>
#include <noise/noiseutils.h>

class Chunk
{
private:
    Block* chunk_buf[16][16][64];
    int start_x, start_z;
public:
    Chunk(int start_x, int start_z, noise::utils::NoiseMap map);

    Block* GetBlockAt(int x, int y, int z);
    bool CoordInChunk(int x, int y);

    void DumpChunk();
};