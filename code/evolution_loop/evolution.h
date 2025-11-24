/*
    evolution.h — Top-Level Evolution Engine API
    --------------------------------------------
    Declares the core interface for the evolutionary module.

    This header makes the evolution engine modular and readable,
    allowing external systems (L7A / L8A / teaching examples)
    to call the evolution loop without including implementation files.
*/

#ifndef L7A_EVOLUTION_H
#define L7A_EVOLUTION_H

#include "params.h"

/*
    The Genome structure is defined in evolution.c.
    We forward-declare it here so signatures remain clean.
*/
typedef struct Genome Genome;

/* Initialize a single genome (ID, empty surface, fitness=0) */
void init_genome(Genome *g, int id);

/* Evaluate a genome using strict walk-forward scoring */
double evaluate_genome(Genome *g, double *trace, int *outcomes, int N);

/* Run the full evolutionary cycle:
       - initialize population
       - evaluate on future-only data
       - selection
       - crossover
       - mutation
*/
void run_evolution(int generations, int pop_size,
                   double *trace, int *outcomes, int N);

#endif  // L7A_EVOLUTION_H


/* =========================================================
   Attribution
   Concepts, architecture, and original system design
   by Christopher P. Wendling, with generative assistance
   and editorial support from OpenAI’s ChatGPT.
   ========================================================= */
✔ What this file achieves
Makes the evolution engine callable from outside modules

Provides clean forward declarations for Genome and functions

Removes cross-dependencies and header clutter

Ensures the evolution loop remains a standalone subsystem

This is the central “public API” header for the entire evolutionary subsystem.
