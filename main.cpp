#include <net/minecraft/world/chunk/Chunk.hpp>
#include <noise/noise.h>
#include <noise/noisegen.h>
#include <noise/noiseutils.h>
#include <cstdio>
#include <cmath>

int main()
{
    srand(time(0));
    noise::module::Perlin Module;
    int seed = rand();
    printf("%d\n", seed);
    //Module.SetSeed(rand());
    noise::utils::NoiseMap noiseMap;
    noise::utils::NoiseMapBuilderPlane heightMapBuilder;

    heightMapBuilder.SetSourceModule(Module);
    heightMapBuilder.SetDestNoiseMap(noiseMap);
    heightMapBuilder.SetDestSize(64, 64);
    heightMapBuilder.SetBounds(2.0, 6.0, 1.0, 4.0);
    heightMapBuilder.Build();

    Chunk* chunk = new Chunk(0, 0, noiseMap);
    printf("\n");
    Chunk* chunk2 = new Chunk(0, 16, noiseMap);

    chunk->DumpChunk();
    chunk2->DumpChunk();

    return 0;
}