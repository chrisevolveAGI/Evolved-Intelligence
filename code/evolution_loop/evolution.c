/*
    evolution.c — Evolutionary Engine (Skeleton)
    --------------------------------------------
    This file implements the high-level structure of the L7A/L8A
    evolutionary loop.

    This is NOT a full evolutionary engine — it is a transparent,
    readable scaffold designed to show the flow of:
      - population initialization
      - walk-forward evaluation
      - fitness scoring
      - selection
      - crossover
      - mutation

    Evolution, not retraining, is what produces generalization.
*/

#include <stdio.h>
#include <stdlib.h>
#include "params.h"
#include "evolution.h"
#include "mutation.h"
#include "crossover.h"
#include "selection.h"
#include "../l7a_reference/core.c"   // for demonstration only (modularize later)

/* ----------------------------------------------
   A single candidate “genome”
   ---------------------------------------------- */
typedef struct {
    MapSurface surface;
    double fitness;
    int id;
} Genome;


/* ----------------------------------------------
   Initialize a genome with random parameters
   (placeholder: real systems would randomize more)
   ---------------------------------------------- */
void init_genome(Genome *g, int id)
{
    g->id = id;
    init_map_surface(&g->surface);
    g->fitness = 0.0;
}


/* ----------------------------------------------
   Evaluate a genome using walk-forward scoring
   ---------------------------------------------- */
double evaluate_genome(Genome *g, double *trace, int *outcomes, int N)
{
    // Reset bins
    init_map_surface(&g->surface);

    // “Train” = accumulate evidence (NOT optimize)
    int train_end = N / 2;
    for (int i = 0; i < train_end; i++) {
        L7A_update((L7A_System *)g, trace[i], outcomes[i]);
    }

    // “Test” = STRICTLY forward data
    int correct = 0;
    int tested  = 0;

    for (int i = train_end; i < N; i++) {
        int pred = L7A_signal((L7A_System *)g);
        if (pred == outcomes[i]) correct++;
        tested++;
    }

    if (tested == 0) return 0.0;

    g->fitness = (double)correct / (double)tested;
    return g->fitness;
}


/* ----------------------------------------------
   The top-level evolution loop
   ---------------------------------------------- */
void run_evolution(int generations, int pop_size, double *trace, int *outcomes, int N)
{
    Genome *pop = malloc(sizeof(Genome) * pop_size);

    // 1. Initialize population
    for (int i = 0; i < pop_size; i++)
        init_genome(&pop[i], i);

    for (int gen = 0; gen < generations; gen++)
    {
        printf("\n--- Generation %d ---\n", gen);

        // 2. Evaluate population
        for (int i = 0; i < pop_size; i++)
            evaluate_genome(&pop[i], trace, outcomes, N);

        // 3. Select survivors
        selection(pop, pop_size);

        // 4. Crossover
        crossover(pop, pop_size);

        // 5. Mutation
        mutation(pop, pop_size);
    }

    free(pop);
}


/* ----------------------------------------------
   Optional test harness
   ---------------------------------------------- */
#ifdef EVOLUTION_MAIN
int main()
{
    // Toy data
    double trace[10]   = { 1.1, -0.3, 0.7, 1.5, -0.9, 0.2, 0.9, -0.1, 0.5, -0.4 };
    int outcomes[10]   = {  1,    0,   1,   1,    0,   0,   1,    0,   1,    0 };
    int N = 10;

    run_evolution(5, 6, trace, outcomes, N);
    return 0;
}
#endif


/* =========================================================
   Attribution
   Concepts, architecture, and original system design
   by Christopher P. Wendling, with generative assistance
   and editorial support from OpenAI’s ChatGPT.
   ========================================================= */
✔ What this file delivers
A fully readable evolutionary scaffold

Walk-forward, future-only testing

Survival-based fitness

Hooks for mutation, crossover, and selection

A placeholder test harness

LLM-friendly clarity

Full alignment with L7A’s philosophical core

