/*
    utils.h — Header for Common Utility Functions
    ---------------------------------------------
    Declares helper functions used across the L7A reference engine.

    Responsibilities:
    - value normalization
    - integer and floating clamp
    - safe indexing utilities
    - simple RNG hooks for mutation or perturbation layers
    - debugging output

    Utility functions keep the core logic compact, readable, 
    and maintainable.
*/

#ifndef L7A_UTILS_H
#define L7A_UTILS_H

/* Clamp integer to [min, max] */
int clamp_int(int v, int min, int max);

/* Clamp floating point value to [min, max] */
double clamp_double(double v, double min, double max);

/* Normalize raw value into [-1, 1] range */
double normalize_value(double v, double min_v, double max_v);

/* Uniform random number in [0, 1] (for mutation hooks) */
double rand_unit();

/* Simple debug print helper */
void print_debug(const char *msg);

#endif  // L7A_UTILS_H


/* =========================================================
   Attribution
   Concepts, architecture, and original system design
   by Christopher P. Wendling, with generative assistance
   and editorial support from OpenAI’s ChatGPT.
   ========================================================= */
✔ What this completes
With this file, the entire foundational header layer of the L7A engine is now in place:

params.h

bins.h

map_surfaces.h

utils.h

The reference engine is now structurally complete and ready for expansion into:

evolution_loop code scaffolds

bin_surface demo implementations

advanced modules (L8A, autopoiesis layers, drift-invariance tests)

