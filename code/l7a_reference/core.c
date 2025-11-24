/*
    core.c — L7A Reference Engine (Skeleton)
    ----------------------------------------
    This file implements the high-level logic of the L7A forecasting engine.
    It is intentionally simple and modular, suitable for teaching, debugging,
    and LLM-friendly analysis.

    Responsibilities:
    - initialize map surfaces
    - walk the trace and update bins
    - compute differential surface
    - produce +1 / 0 / -1 final classification
*/

#include <stdio.h>
#include <stdlib.h>
#include "params.h"
#include "bins.h"
#include "map_surfaces.h"
#include "utils.h"

/* ---------------------------------------------------------
   Core L7A structure
   --------------------------------------------------------- */
typedef struct {
    MapSurface surface;
} L7A_System;


/* ---------------------------------------------------------
   Initialize a new L7A system with empty bins
   --------------------------------------------------------- */
void L7A_init(L7A_System *sys)
{
    init_map_surface(&sys->surface);
}


/* ---------------------------------------------------------
   Process a single data point
   --------------------------------------------------------- */
void L7A_update(L7A_System *sys, double value, int actual_outcome)
{
    // Map value → (x, y) coordinates
    int x = map_to_x(value);
    int y = map_to_y(value);

    // Update bin for this coordinate
    update_bin(&sys->surface.bins[x][y], actual_outcome);
}


/* ---------------------------------------------------------
   Compute differential probability surface
   --------------------------------------------------------- */
double L7A_signal(const L7A_System *sys)
{
    double sum = 0.0;
    int count = 0;

    for (int x = 0; x < GRID_W; x++) {
        for (int y = 0; y < GRID_H; y++) {

            double p = smoothed_prob(&sys->surface.bins[x][y]);
            
            // Differential contribution: P(up) - 0.5
            sum += (p - 0.5);
            count++;
        }
    }

    // Aggregate signal
    double avg = sum / (double)count;

    // Decision rule (+1 / 0 / -1)
    if (avg >  DIFF_THRESHOLD) return +1;
    if (avg < -DIFF_THRESHOLD) return -1;
    return 0;
}


/* ---------------------------------------------------------
   Example usage: (illustrative only)
   --------------------------------------------------------- */
#ifdef L7A_MAIN
int main()
{
    L7A_System sys;
    L7A_init(&sys);

    // Example input data stream
    double sample_trace[] = { 1.2, -0.4, 0.9, 1.5, -0.7 };
    int sample_outcome[] = { 1, 0, 1, 1, 0 };
    int N = 5;

    for (int i = 0; i < N; i++) {
        L7A_update(&sys, sample_trace[i], sample_outcome[i]);
    }

    int signal = (int)L7A_signal(&sys);
    printf("Final L7A signal = %d\n", signal);

    return 0;
}
#endif
