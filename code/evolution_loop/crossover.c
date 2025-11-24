/*
    crossover.c — Evolutionary Crossover Operators
    ----------------------------------------------
    Crossover mixes the structural features of two parent genomes
    to form new offspring genomes.

    In L7A/L8A, crossover can combine:
      - bin surface regions
      - smoothing parameters
      - scale settings
      - coordinate transforms
      - mutation strategies (in advanced systems)

    This file implements a minimal, readable crossover operation
    suitable for teaching and scaffolding.
*/

#include <stdio.h>
#include <stdlib.h>
#include "params.h"
#include "crossover.h"
#include "../l7a_reference/utils.h"
#include "../l7a_reference/map_surfaces.h"


/* ---------------------------------------------------------
   Simple crossover: mix random rectangular regions of the
   parents’ map surfaces into the child.
   --------------------------------------------------------- */
void crossover_pair(Genome *a, Genome *b)
{
    // Select random region
    int x1 = (int)(rand_unit() * (GRID_W - 1));
    int x2 = (int)(rand_unit() * (GRID_W - 1));
    int y1 = (int)(rand_unit() * (GRID_H - 1));
    int y2 = (int)(rand_unit() * (GRID_H - 1));

    if (x1 > x2) { int tmp = x1; x1 = x2; x2 = tmp; }
    if (y1 > y2) { int tmp = y1; y1 = y2; y2 = tmp; }

    for (int x = x1; x <= x2; x++)
    {
        for (int y = y1; y <= y2; y++)
        {
            // 50% chance swap each bin
            if (rand_unit() < 0.5)
            {
                Bin temp = a->surface.bins[x][y];
                a->surface.bins[x][y] = b->surface.bins[x][y];
                b->surface.bins[x][y] = temp;
            }
        }
    }
}


/* ---------------------------------------------------------
   Apply crossover across the entire population
   --------------------------------------------------------- */
void crossover(Genome *pop, int pop_size)
{
    for (int i = 0; i < pop_size - 1; i += 2)
    {
        if (rand_unit() < 0.25)    // 25% crossover probability
        {
            crossover_pair(&pop[i], &pop[i + 1]);
            print_debug("Crossover applied to genome pair.");
        }
    }
}


/* =========================================================
   Attribution
   Concepts, architecture, and original system design
   by Christopher P. Wendling, with generative assistance
   and editorial support from OpenAI’s ChatGPT.
   ========================================================= */
✔ What this file provides
Functionality
Combines structural regions from two genomes

Simulates biological recombination

Enables discovery of new manifold geometries

Supports emergent stability by blending strong survivors

Architectural clarity
Completely modular

Extremely readable

Fully aligned with L7A evolutionary mechanics

Safe, small-scale structural recombination

Why it matters
Crossover is often where the largest leaps in structure occur in evolved intelligence systems.
It’s the mechanism that allows the engine to explore combinations no gradient-based system could propose.

