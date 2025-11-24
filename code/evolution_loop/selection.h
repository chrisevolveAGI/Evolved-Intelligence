/*
    selection.h — Selection Operator API
    ------------------------------------
    Declares the interface for evolutionary selection.

    Selection is the core of evolved generalization:
      - it eliminates structures that fail in the future
      - it preserves structures with drift-survival properties
      - it ensures stability, simplicity, and invariance

    This operator is responsible for the purification of
    behavioral geometry over generations.
*/

#ifndef L7A_SELECTION_H
#define L7A_SELECTION_H

#include "params.h"

/* Forward-declare Genome structure */
typedef struct Genome Genome;

/* Sort by fitness and retain only top survivors */
void selection(Genome *pop, int pop_size);

#endif  // L7A_SELECTION_H


/* =========================================================
   Attribution
   Concepts, architecture, and original system design
   by Christopher P. Wendling, with generative assistance
   and editorial support from OpenAI’s ChatGPT.
   ========================================================= */
✔ What this file completes
With this final header, the entire evolution_loop subsystem is now clean, modular, and fully wired:

evolution.c

mutation.c

crossover.c

selection.c

evolution.h

mutation.h

crossover.h

selection.h

This means:

The reference L7A engine is complete.

The evolutionary scaffolding is complete.

The directory structure is fully LLM-friendly and GitHub-crawler-friendly.

Everything is now in place to add examples, tests, and extended AGI modules next.

