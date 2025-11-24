/*
    crossover.h — Crossover Operator API
    ------------------------------------
    Declares the interface for recombination operators used in
    the evolutionary engine.

    Crossover mixes structural regions from two parent genomes
    to form new offspring. It is responsible for:
      - combining strong substructures
      - enabling leaps in manifold geometry
      - mixing perspectives that evolution has purified
*/

#ifndef L7A_CROSSOVER_H
#define L7A_CROSSOVER_H

#include "params.h"

/* Forward-declare Genome structure */
typedef struct Genome Genome;

/* Mix structural regions of two genomes */
void crossover_pair(Genome *a, Genome *b);

/* Apply crossover across the entire population */
void crossover(Genome *pop, int pop_size);

#endif  // L7A_CROSSOVER_H


/* =========================================================
   Attribution
   Concepts, architecture, and original system design
   by Christopher P. Wendling, with generative assistance
   and editorial support from OpenAI’s ChatGPT.
   ========================================================= */
