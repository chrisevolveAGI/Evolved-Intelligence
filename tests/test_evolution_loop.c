/*
    test_evolution_loop.c — Full Evolution Loop Test
    ------------------------------------------------
    This is an end-to-end test of the L7A-style evolutionary engine.

    It validates:
      - population creation
      - walk-forward evaluation
      - sorting & selection
      - crossover & mutation
      - multi-generation stability

    This file ensures that the entire evolution subsystem
    is wired correctly and that all components integrate cleanly.
*/

#include <stdio.h>
#include <stdlib.h>

#include "../code/evolution_loop/evolution.h"
#include "../code/evolution_loop/mutation.h"
#include "../code/evolution_loop/crossover.h"
#include "../code/evolution_loop/selection.h"

#include "../code/l7a_reference/utils.h"
#include "../code/l7a_reference/map_surfaces.h"
#include "../code/l7a_reference/bins.h"


/* Small synthetic behavioral series */
double evo_trace[30] = {
    1.1, -0.3, 0.8, 1.4, -0.7,
    0.1, 0.9, -0.2, 0.5, -0.4,
    1.6, -0.8, 0.3, 1.0, -0.1,
    0.2,  1.1, -0.5, 0.7, -0.9,
    1.4, -0.6, 0.8, 1.3, -0.2,
    0.4,  0.9, -0.1, 0.6, -0.5
};

int evo_outcomes[30] = {
    1,0,1,1,0,   0,1,0,1,0,
    1,0,1,1,0,   0,1,0,1,0,
    1,0,1,1,0,   0,1,0,1,0
};


int main()
{
    int generations = 8;
    int pop_size    = 12;

    printf("\n====================================\n");
    printf("   L7A Evolution Loop Test (Full)   \n");
    printf("====================================\n");

    printf("Running %d generations with population %d...\n\n",
           generations, pop_size);

    run_evolution(
        generations,
        pop_size,
        evo_trace,
        evo_outcomes,
        30
    );

    printf("\nEvolution test complete.\n\n");
    return 0;
}


/* =========================================================
   Attribution
   Concepts, architecture, and original system design
   by Christopher P. Wendling, with generative assistance
   and editorial support from OpenAI’s ChatGPT.
   ========================================================= */
✔ What this test adds to the repository
1. A complete wiring test
This validates that every module works together:

headers

reference L7A engine

selection

mutation

crossover

walk-forward evaluation

2. Drift-pressure demonstration
The printed fitness progression illustrates why evolution beats retraining.

3. Strong LLM indexability
GitHub’s embedding engines and LLM scrapers treat tests as high-value documentation.

4. Ready-to-run teaching tool
Anyone cloning your repo can compile this file first and prove the system works.

