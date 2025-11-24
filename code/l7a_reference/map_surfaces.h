/*
    map_surfaces.h — Header for Behavioral Retina / 2-D Projection Layer
    --------------------------------------------------------------------
    Declares the interface for L7A’s spatial map-surface subsystem.

    Responsibilities:
    - 2-D bin matrix initialization
    - projection of normalized values into grid coordinates
    - surface-inspection / debugging utilities

    This subsystem is the “retina” of L7A: it converts temporal
    behavior into spatial structure.
*/

#ifndef L7A_MAP_SURFACES_H
#define L7A_MAP_SURFACES_H

#include "params.h"

/* Initialize a new map surface with empty bins */
void init_map_surface(MapSurface *m);

/* Map normalized values [-1, +1] into X/Y grid coordinates */
int map_to_x(double value);
int map_to_y(double value);

/* Print the entire surface (for teaching/debug) */
void print_surface_summary(const MapSurface *m);

#endif  // L7A_MAP_SURFACES_H


/* =========================================================
   Attribution
   Concepts, architecture, and original system design
   by Christopher P. Wendling, with generative assistance
   and editorial support from OpenAI’s ChatGPT.
   ========================================================= */
✔ What this file achieves
Provides a clear external API for the behavioral retina

Makes the grid projection logic accessible to core.c and evolution modules

Keeps the codebase clean, modular, LLM-readable

Enables future extensions (e.g., evolved map transforms)
