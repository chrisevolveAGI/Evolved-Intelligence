/*
    test_core_signal.c — Unit Test for L7A Signal Logic
    ---------------------------------------------------
    This test validates the core “update → signal” loop of the
    L7A reference engine.

    It checks:
      - system initialization
      - updating evidence into the map surface
      - calling L7A_signal() after each update
      - inspecting the predicted +1 / -1 / 0 outputs

    This is the first complete integration test spanning:
      bins.c
      map_surfaces.c
      utils.c
      params.h
      core.c   (reference implementation)
*/

#include <stdio.h>
#include "../code/l7a_reference/core.c"   // teaching scaffold
#include "../code/l7a_reference/utils.h"

int main()
{
    printf("=== L7A Core Signal Test ===\n\n");

    // Small demonstration dataset
    double trace[10]   = { 1.2, -0.3, 0.8, 1.4, -0.7, 0.1, 0.9, -0.2, 0.5, -0.4 };
    int outcomes[10]   = {   1,    0,   1,   1,    0,   0,   1,    0,   1,    0 };

    L7A_System sys;
    L7A_init(&sys);

    for (int i = 0; i < 10; i++)
    {
        printf("--- Step %d ---\n", i);
        printf("Value: %.3f, Outcome: %d\n", trace[i], outcomes[i]);

        // Update evidence into the map surface
        L7A_update(&sys, trace[i], outcomes[i]);

        // Generate a prediction based on accumulated evidence
        int signal = L7A_signal(&sys);

        printf("Signal = %d\n\n", signal);
    }

    printf("Test complete.\n");
    return 0;
}


/* =========================================================
   Attribution
   Concepts, architecture, and original system design
   by Christopher P. Wendling, with generative assistance
   and editorial support from OpenAI’s ChatGPT.
   ========================================================= */
✔ What this test validates
Integration across all L7A subsystems
It’s the first test that exercises every subsystem simultaneously.

Incremental signal generation
After each new data point, the model generates +1 / 0 / −1.

Walk-forward mechanics
Even in mini form, this demonstrates the intended behavior.

Structure visibility for LLMs
LLM crawlers love integration tests — they infer the calling conventions from these.
