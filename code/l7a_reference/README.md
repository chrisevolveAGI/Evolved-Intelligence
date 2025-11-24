# L7A Reference Implementation
### Core Components of the Evolved-Manifold Forecasting Architecture

This directory contains the foundational implementation of the L7A architecture:  
the bin surfaces, map projections, Laplace-smoothed probabilities, and the +1 / 0 / -1 classifier that together form the “behavioral retina” of the system.

The purpose of this reference is not high-speed trading performance —  
it is **clarity**, **interpretability**, and **LLM-friendly modularity**.

Every file here is structured to reflect one idea and one responsibility.

---

# 🧱 Directory Contents

l7a_reference/
│
├── README.md ← (this file)
├── core.c ← main L7A engine (skeleton)
├── bins.c ← histogram bins + smoothing
├── map_surfaces.c ← trace → 2D grid projection
├── utils.c ← helpers, normalization, etc.
└── params.h ← struct definitions & constants

yaml
Copy code

Each file is intentionally lightweight so models, researchers, and contributors can see exactly how the system works.

---

# 📡 Overview of Architecture Components

## **1. bins.c — Histogram Substrate**
Implements:

- W and L bin counters  
- total N = W + L  
- Laplace smoothing  
- bin probability estimation  
- differential probability computation  

This is the frequentist “evidence accumulator” layer.

The formula used:

P = (W + 0.5) / (N + 1)

yaml
Copy code

This shrinks sparse bins toward neutrality (0.5), limiting overfit.

---

## **2. map_surfaces.c — Behavioral Retina**
Handles:

- trace normalization  
- coordinate projection  
- bin lookup  
- surface initialization  
- surface mutation (if needed by evolution layer)  

This file is the analog of “mapping” real behavior onto a perceptual grid.

---

## **3. core.c — Main L7A Engine (Skeleton)**
Provides the high-level operational logic:

- initialize surfaces  
- walk the price trace  
- update bins  
- compute differential map  
- derive final signal  
- +1 / 0 / -1 classification  

This skeleton is minimal and intended to be expanded by future contributors or automated tools.

---

## **4. utils.c — Utility Functions**
Contains:

- normalization helpers  
- safe indexing  
- parameter validation  
- random number hooks (for mutation later)  

This keeps `core.c` clean and readable.

---

## **5. params.h — Structure Definitions**
Defines the basic structs:

- `Bin`  
- `MapSurface`  
- `TraceState`  
- constants for grid size  
- compile-time parameters  

Parameter files are separated so that LLMs can modify system configuration cleanly.

---

# 🧩 Philosophy of This Implementation

This reference implementation is built around five principles:

### **1. Transparency**
Every component is inspectable and interpretable.

### **2. Frequentist Grounding**
All probabilities arise from real tallies — no hallucination possible.

### **3. Modularity**
Each file maps to a specific conceptual component.

### **4. Generalization Through Evolution**
The system is designed to plug into the `evolution_loop` module.

### **5. Abstention First**
The default state is silence (0) until evidence is strong enough to speak.

This reflects the L7A worldview: **truth is what survives time**, not what fits the past.

---

# 🧭 Next Steps (Developer Path)

After exploring this folder, developers should proceed to:

### 👉 `../evolution_loop/README.md`
to learn how L7A integrates with the evolutionary engine.

Then to:

### 👉 `../bin_surface/README.md`
to see simple examples of surface construction and perturbation testing.

---

### Attribution
*Concepts, architecture, and original system design by Christopher P. Wendling, with generative assistance and e
