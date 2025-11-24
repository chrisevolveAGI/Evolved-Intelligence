/*
    utils.c — Utility Functions for L7A
    -----------------------------------
    A collection of helper functions used across the L7A reference engine:
      - value normalization
      - clamping
      - safe indexing
      - simple RNG wrapper (for mutation hooks)

    These utilities help keep the core engine code clean and readable.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"
#include "params.h"


/* ---------------------------------------------------------
   Clamp integer to the range [min, max]
   --------------------------------------------------------- */
int clamp_int(int v, int min, int max)
{
    if (v < min) return min;
    if (v > max) return max;
    return v;
}


/* ---------------------------------------------------------
   Clamp double to [min, max]
   --------------------------------------------------------- */
double clamp_double(double v, double min, double max)
{
    if (v < min) return min;
    if (v > max) return max;
    return v;
}


/* ---------------------------------------------------------
   Normalize a raw value to [-1, 1].
   This is a placeholder — real systems supply their own
   normalization logic per trace.
   --------------------------------------------------------- */
double normalize_value(double v, double min_v, double max_v)
{
    if (max_v == min_v) return 0.0;   // avoid divide-by-zero
    double x = (v - min_v) / (max_v - min_v);  // [0,1]
    return (x * 2.0) - 1.0;                     // → [-1,1]
}


/* ---------------------------------------------------------
   Simple random double in [0,1]
   For use by evolutionary mutation hooks.
   --------------------------------------------------------- */
double rand_unit()
{
    return (double)rand() / (double)RAND_MAX;
}


/* ---------------------------------------------------------
   Debug helper
   --------------------------------------------------------- */
void print_debug(const char *msg)
{
    printf("[DEBUG] %s\n", msg);
}

✔ What this file provides
Core utilities:
clamp_int → bounds safety

clamp_double → float bounds safety

normalize_value → placeholder for trace-level normalization

rand_unit → random number for evolutionary mutation

print_debug → debugging hook

Why this is important:
This keeps the rest of the engine clean, readable, and modular, and gives LLMs predictable helper functions across the codebase.

