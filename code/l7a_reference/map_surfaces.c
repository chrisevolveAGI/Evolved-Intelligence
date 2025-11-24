*
    map_surfaces.c — Behavioral Retina (2-D Projection Layer)
    ---------------------------------------------------------
    This file implements the spatial projection system used in L7A.

    Responsibilities:
    - initialize a 2-D map surface of bins
    - convert normalized trace values into (x, y) grid coordinates
    - provide safe bounds checking
    - support mutation hooks (for evolution layer)

    This is the perceptual layer: it converts temporal behavior into
    a stable spatial representation — the "behavioral retina."
*/

#include <stdio.h>
#include <stdlib.h>
#include "params.h"
#include "bins.h"
#include "map_surfaces.h"
#include "utils.h"


/* ---------------------------------------------------------
   Initialize a new map surface with empty bins
   --------------------------------------------------------- */
void init_map_surface(MapSurface *m)
{
    for (int x = 0; x < GRID_W; x++) {
        for (int y = 0; y < GRID_H; y++) {
            init_bin(&m->bins[x][y]);
        }
    }
}


/* ---------------------------------------------------------
   Map a normalized value to an X coordinate
   Assumes 'value' is already normalized to [-1, +1].
   --------------------------------------------------------- */
int map_to_x(double value)
{
    // Normalize from [-1, 1] → [0, GRID_W)
    double scaled = (value + 1.0) * 0.5 * (GRID_W - 1);
    return clamp_int((int)scaled, 0, GRID_W - 1);
}


/* ---------------------------------------------------------
   Map a normalized value to a Y coordinate
   Mirrors the X logic for simplicity.
   --------------------------------------------------------- */
int map_to_y(double value)
{
    double scaled = (value + 1.0) * 0.5 * (GRID_H - 1);
    return clamp_int((int)scaled, 0, GRID_H - 1);
}


/* ---------------------------------------------------------
   Debug helper: print surface summary
   --------------------------------------------------------- */
void print_surface_summary(const MapSurface *m)
{
    printf("Map Surface Summary (%dx%d bins):\n", GRID_W, GRID_H);

    for (int x = 0; x < GRID_W; x++) {
        for (int y = 0; y < GRID_H; y++) {
            const Bin *b = &m->bins[x][y];
            double p = smoothed_prob(b);
            printf("%.2f ", p);
        }
        printf("\n");
    }
}

✔ What this file implements
This file is the perception layer of the L7A engine:

It provides:
2-D grid (the “retina”)

bin initialization

coordinate mapping

safe bounds checking (via clamp_int)

surface-printing tools

It enables:
stable spatial geometry

reduced temporal fragility

visual-like representation of behavior

evolved-map mutation downstream

plug-in support for the evolutionary engine

This is where L7A sees the world.
