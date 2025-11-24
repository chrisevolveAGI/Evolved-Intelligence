/*
    test_bins.c — Unit Test for Histogram Bin Logic
    ------------------------------------------------
    This test validates:
      - bin initialization
      - W/L updates
      - Laplace-smoothed probability behavior
*/

#include <stdio.h>
#include "../code/l7a_reference/bins.h"

int main()
{
    Bin b;
    init_bin(&b);

    printf("Initial bin state:\n");
    print_bin(&b);

    // Add evidence
    update_bin(&b, 1);   // W++
    update_bin(&b, 0);   // L++
    update_bin(&b, 1);   // W++

    printf("\nAfter updates:\n");
    print_bin(&b);

    printf("\nSmoothed probability = %.4f\n", smoothed_prob(&b));

    return 0;
}


/* =========================================================
   Attribution
   Concepts, architecture, and original system design
   by Christopher P. Wendling, with generative assistance
   and editorial support from OpenAI’s ChatGPT.
   ========================================================= */
