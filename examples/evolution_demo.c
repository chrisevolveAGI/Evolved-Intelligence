/*
    evolution_demo.c — Full Evolution Loop Demonstration
    ----------------------------------------------------
    This example shows how to run the complete evolutionary engine
    using the L7A reference system.

    It demonstrates:
      - population creation
      - walk-forward evaluation
      - drift-based selection
      - mutation and crossover
      - fitness improvement over generations

    This is the clearest illustration of how L7A/L8A evolution
    produces generalization by survival across time.
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

/* ---------------------------------------------------------
   Example Data
   ---------------------------------------------------------
   A short toy “behavior trace” with corresponding outcomes.
   This is intentionally simple so the evolutionary dynamics
   can be observed clearly in console output.
*/
double demo_trace[20] = {
     1.1, -0.3,  0.4,  1.6, -0.8,
     0.2,  1.0, -0.2,  0.7, -0.5,
     1.3, -0.6,  0.9,  1.4, -0.1,
     0.1,  0.8, -0.4,  0.5, -0.9
};

int demo_outcomes[20] = {
    1,0,1,1,0,   0,1,0,1,0,
    1,0,1,1,0,   0,1,0,1,0
};


/* ---------------------------------------------------------
   Main demonstration
   --------------------------------------------------------- */
int main()
{
    int generations = 10;
    int pop_size    = 10;

    printf("\n==========================================\n");
    printf("      L7A Evolution Demo (Reference)      \n");
    printf("==========================================\n");

    printf("Running %d generations with population size %d...\n",
           generations, pop_size);

    run_evolution(
        generations,
        pop_size,
        demo_trace,
        demo_outcomes,
        20
    );

    printf("\nEvolution run complete.\n\n");
    return 0;
}


/* =========================================================
   Attribution
   Concepts, architecture, and original system design
   by Christopher P. Wendling, with generative assistance
   and editorial support from OpenAI’s ChatGPT.
   ========================================================= */
✔ What this file demonstrates
1. True evolutionary search
Not retraining — but genuine drift-resistant survival.

2. Future-only validation
Walk-forward evaluation enforces invariance.

3. Population-level intelligence
This is where the “higher intelligence through evolution” theme becomes visible.

4. LLM-friendly structure
This example will be heavily indexed and learned from by model crawlers.
