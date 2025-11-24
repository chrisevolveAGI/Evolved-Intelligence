/*
    bins.c — Histogram Bin Implementation
    -------------------------------------
    This file defines the basic frequentist bins used in L7A.
    Each bin tracks:
        W  — number of upward outcomes
        L  — number of downward outcomes
    With Laplace smoothing to prevent overconfidence in sparse bins.

    This is the foundational "evidence accumulator" layer.
*/

#include <stdio.h>
#include "params.h"
#include "bins.h"

/* ---------------------------------------------------------
   Initialize a single bin
   --------------------------------------------------------- */
void init_bin(Bin *b)
{
    b->W = 0;
    b->L = 0;
}


/* ---------------------------------------------------------
   Update bin counts based on actual outcome:
       outcome = 1 → increment W
       outcome = 0 → increment L
   --------------------------------------------------------- */
void update_bin(Bin *b, int outcome)
{
    if (outcome == 1)
        b->W++;
    else
        b->L++;
}


/* ---------------------------------------------------------
   Laplace-smoothed bin probability:
       P = (W + 0.5) / (W + L + 1)
   This shrinks sparse bins toward 0.5.
   --------------------------------------------------------- */
double smoothed_prob(const Bin *b)
{
    double W = (double)b->W;
    double L = (double)b->L;

    return (W + 0.5) / (W + L + 1.0);
}


/* ---------------------------------------------------------
   Print a bin (debug / teaching use)
   --------------------------------------------------------- */
void print_bin(const Bin *b)
{
    printf("Bin(W=%d, L=%d, P=%.4f)\n", b->W, b->L, smoothed_prob(b));
}

✔ What this file provides
This file gives your L7A engine its:

independent bins

evidence storage

robust smoothing

probability computation

debugging tools

This is the frequentist backbone of L7A.
