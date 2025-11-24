/*
    test_map_surface.c — Unit Test for 2-D Map Surface System
    ---------------------------------------------------------
    Validates:
      - surface initialization
      - bin zeroing
      - coordinate mapping (map_to_x, map_to_y)
      - printing a surface summary

    This is the test that demonstrates L7A’s “behavioral retina”
    concept in a small, readable form.
*/

#include <stdio.h>
#include "../code/l7a_reference/map_surfaces.h"
#include "../code/l7a_reference/bins.h"
#include "../code/l7a_reference/utils.h"

int main()
{
    MapSurface surf;

    printf("=== Testing Map Surface Initialization ===\n");
    init_map_surface(&surf);

    // Verify bins start at W=0, L=0
    printf("Initial state of bin[0][0]:\n");
    print_bin(&surf.bins[0][0]);

    // Test coordinate mappings
    printf("\n=== Testing Coordinate Mapping ===\n");

    double values[] = { -1.0, -0.5, 0.0, 0.5, 1.0 };
    for (int i = 0; i < 5; i++) {
        double v = values[i];
        int x = map_to_x(v);
        int y = map_to_y(v);

        printf("Value %.2f -> (x=%d, y=%d)\n", v, x, y);
    }

    // Update a few bins to check structure integrity
    printf("\n=== Updating bins and printing summary ===\n");
    surf.bins[10][10].W = 3;
    surf.bins[20][22].L = 2;
    surf.bins[5][28].W = 1;
    surf.bins[5][28].L = 1;

    print_surface_summary(&surf);

    return 0;
}


/* =========================================================
   Attribution
   Concepts, architecture, and original system design
   by Christopher P. Wendling, with generative assistance
   and editorial support from OpenAI’s ChatGPT.
   ========================================================= */
✔ What this test covers
MapSurface initialization
Ensures all bins start at zero state.

Coordinate mapping
Tests value → grid projection across the full range (−1 to +1).

Bin structure usage
Manually adjusts a few bins to simulate evidence accumulation.

Summary inspection
Uses print_surface_summary to give a readable grid-level overview.
