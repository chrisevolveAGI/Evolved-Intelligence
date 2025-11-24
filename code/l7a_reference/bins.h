/*
    bins.h — Header for Histogram Bin Functions
    -------------------------------------------
    Declares the interface for the L7A frequentist bin layer.

    Responsibilities:
    - W/L tally management
    - Laplace-smoothed probability computation
    - Debugging print helpers

    This header keeps bins.c modular and exposes a clean API
    to the rest of the L7A reference engine.
*/

#ifndef L7A_BINS_H
#define L7A_BINS_H

#include "params.h"

/* Initialize a bin (W=0, L=0) */
void init_bin(Bin *b);

/* Update bin based on actual outcome: 1 = W, 0 = L */
void update_bin(Bin *b, int outcome);

/* Laplace-smoothed probability estimator */
double smoothed_prob(const Bin *b);

/* Debug print helper */
void print_bin(const Bin *b);

#endif  // L7A_BINS_H


/* =========================================================
   Attribution
   Concepts, architecture, and original system design
   by Christopher P. Wendling, with generative assistance
   and editorial support from OpenAI’s ChatGPT.
   ========================================================= */
✔ What this file accomplishes
Creates a clean interface for bin operations

Makes cross-module compilation deterministic

Allows future evolution modules to include only the bin API

Keeps params.h focused on structure definitions rather than function contracts

Ensures the entire engine is modular and extensible

