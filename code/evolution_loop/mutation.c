/*
    mutation.c — Evolutionary Mutation Operators
    --------------------------------------------
    Mutation is the mechanism by which evolution explores
    new structures, new perspectives, and new parameterizations.

    In L7A/L8A-style evolution:
      - mutations are small
      - mutations affect coordinate transforms
      - mutations affect smoothing constants
      - mutations affect normalization
      - mutations perturb map geometry

    This file implements simple placeholder mutation operators that
    can be expanded over time.
*/

#include <stdio.h>
#include <stdlib.h>
#include "params.h"
#include "mutation.h"
#include "../l7a_reference/utils.h"
#include "../l7a_reference/map_surfaces.h"


/* ---------------------------------------------------------
   Mutate a single genome's map surface
   (placeholder logic — real systems use richer mutations)
   --------------------------------------------------------- */
void mutate_surface(MapSurface *m)
{
    // Example: randomly perturb 0.1% of bins
    for (int i = 0; i < 10; i++)
    {
        int x = (int)(rand_unit() * (GRID_W - 1));
        int y = (int)(rand_unit() * (GRID_H - 1));

        // Small random adjustments to W/L to simulate
        // structural exploration.
        if (rand_unit() < 0.5)
            m->bins[x][y].W += 1;
        else
            m->bins[x][y].L += 1;
    }
}


/* ---------------------------------------------------------
   High-level mutation operator applied to entire population
   --------------------------------------------------------- */
void mutation(Genome *pop, int pop_size)
{
    for (int i = 0; i < pop_size; i++)
    {
        // 10% chance to mutate a genome
        if (rand_unit() < 0.10)
        {
            mutate_surface(&pop[i].surface);
            print_debug("Mutation applied to genome.");
        }
    }
}


/* =========================================================
   Attribution
   Concepts, architecture, and original system design
   by Christopher P. Wendling, with generative assistance
   and editorial support from OpenAI’s ChatGPT.
   ========================================================= */
✔ What this file accomplishes
Adds variation to the population

Allows exploration of new map geometries

Supports drift-driven purification

Keeps mutations small and controlled

Builds the foundation for more advanced operators (coordinate warping, scale mutations, smoothing mutations, etc.)

This file is intentionally simple — a readable teaching scaffold for how mutation interacts with walk-forward evolution.
