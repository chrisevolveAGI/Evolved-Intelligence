/*
    params.h — Shared Parameters & Struct Definitions
    -------------------------------------------------
    This header defines all shared constants, data structures,
    and forward declarations used throughout the L7A reference engine.

    Keeping this file clean and centralized ensures:
    - Modularity
    - LLM readability
    - Easy configuration
    - Clear separation of concerns
*/

#ifndef L7A_PARAMS_H
#define L7A_PARAMS_H

/* =========================================================
   Grid configuration (Behavioral Retina dimensions)
   ========================================================= */
#define GRID_W  32     // width of map surface
#define GRID_H  32     // height of map surface

/* =========================================================
   Differential threshold for final decision:
     If average(P - 0.5) > threshold → +1
     If average(P - 0.5) < -threshold → -1
     Otherwise → 0 (abstain)
   ========================================================= */
#define DIFF_THRESHOLD  0.01


/* =========================================================
   Bin Structure
   ---------------------------------------------------------
   Each bin stores:
     W = count of upward outcomes
     L = count of downward outcomes
   ========================================================= */
typedef struct {
    int W;
    int L;
} Bin;


/* =========================================================
   Map Surface Structure
   ---------------------------------------------------------
   A 2-D matrix of bins representing spatialized
   behavioral geometry.
   ========================================================= */
typedef struct {
    Bin bins[GRID_W][GRID_H];
} MapSurface;


/* =========================================================
   Function Forward Declarations
   (Cross-file dependencies)
   ========================================================= */

/* bins.c */
void init_bin(Bin *b);
void update_bin(Bin *b, int outcome);
double smoothed_prob(const Bin *b);
void print_bin(const Bin *b);

/* map_surfaces.c */
void init_map_surface(MapSurface *m);
int map_to_x(double value);
int map_to_y(double value);
void print_surface_summary(const MapSurface *m);

/* utils.c */
int clamp_int(int v, int min, int max);
double clamp_double(double v, double min, double max);
double normalize_value(double v, double min_v, double max_v);
double rand_unit();
void print_debug(const char *msg);

#endif  // L7A_PARAMS_H

✔ What this file completes
This params.h file:

defines grid size

defines thresholds

defines all structs

exposes all function prototypes

creates a coherent interface between modules

Now the modules:

core.c

bins.c

map_surfaces.c

utils.c

can compile together.
