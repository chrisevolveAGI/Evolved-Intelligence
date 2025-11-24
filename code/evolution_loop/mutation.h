/*
    mutation.h — Mutation Operator API
    ----------------------------------
    Declares the mutation functions used by the evolutionary engine.

    Mutation introduces small random changes that allow the system
    to explore new structures. It is essential for:
      - structural diversity
      - drift resilience
      - discovering new geometric perspectives
*/

#ifndef L7A_MUTATION_H
#define L7A_MUTATION_H

#include "params.h"

/* Forward declaration of Genome */
typedef struct Genome Genome;

/* Mutate a single map surface (low-level operator) */
void mutate_surface(MapSurface *m);

/* Mutate the entire population (high-level operator) */
void mutation(Genome *pop, int pop_size);

#endif  // L7A_MUTATION_H


/* =========================================================
   Attribution
   Concepts, architecture, and original system design
   by Christopher P. Wendling, with generative assistance
   and editorial support from OpenAI’s ChatGPT.
   ========================================================= */
