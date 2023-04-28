#ifndef ALGO_H
#define ALGO_H

#include "graph.h"

void parcours_profondeur(Graph *g, int sommet_depart);
void visiter(Graph *g, int sommet, int *state);
void parcours_largeur(Graph *g, int sommet_depart);

#endif