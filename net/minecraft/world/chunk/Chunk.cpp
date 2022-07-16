#include <net/minecraft/world/chunk/Chunk.hpp>

Chunk::Chunk(int x, int z, noise::utils::NoiseMap noise)
{
    start_x = x;
    start_z = z;

    for (x = 0; x < 16; x++)
    {
        for (z = 0; z < 16; z++)
        {
            int height = round(noise.GetValue(x + start_x, z + start_z) / 2 * 10);
            printf("%d ", height);
            height += 32;
            chunk_buf[x][z][height] = Blocks::DIRT;
            for (int y = 0; y < height; y++)
            {
                if (y != 0)
                    chunk_buf[x][z][y] = Blocks::STONE;
                else
                    chunk_buf[x][z][y] = Blocks::BEDROCK;
            }
            for (int y = height+1; y < 64; y++)
            {
                chunk_buf[x][z][y] = Blocks::AIR;
            }
        }
        printf("\n");
    }
}

Block* Chunk::GetBlockAt(int x, int y, int z)
{
    if (!CoordInChunk(x, z) || y >= 64)
    {
        printf("[ERROR] Tried to retrieve block at (%d, %d, %d) (WRONG_CHUNK)\n", x, y, z);
        exit(1);
    }
    return chunk_buf[x-start_x][z-start_z][y];
}

bool Chunk::CoordInChunk(int x, int z)
{
    return (x >= start_x && x < start_x+64) && (z >= start_z && z < start_z+64);
}

void Chunk::DumpChunk()
{
    for (int x = 0; x < 16; x++)
    {
        for (int y = 63; y > -1; y--)
        {
            for (int z = 0; z < 16; z++)
            {
                Block* block = GetBlockAt(x+start_x, y, z+start_z);
                if (block == Blocks::AIR)
                {
                    printf(" ");
                }
                else if (block == Blocks::DIRT)
                {
                    printf("#");
                }
                else if (block == Blocks::STONE)
                {
                    printf("+");
                }
                else
                {
                    printf("=");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}