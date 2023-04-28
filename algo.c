#include <stdio.h>
#include <stdlib.h>
#include "algo.h"
#include "queue.h"

void parcours_profondeur(Graph *g, int sommet_depart)
{
    int *state = (int *)malloc(sizeof(int) * g->n_vertex);
    for (int i = 0 ; i < g->n_vertex ; i++)
    {
        state[i] = 0;   
    }
    visiter(g, sommet_depart, state);
}

void visiter(Graph *g, int sommet, int *state)
{
    state[sommet] = 1;
    printf("Sommet %d is visited\n", sommet);
    for (int i = 0 ; i < g->n_vertex ; i++)
    {
        if (g->matrix[sommet][i] != 0 && state[i] == 0)
        {
            visiter(g, i, state);
        }
    }
}

void parcours_largeur(Graph *g, int sommet_depart)
{
    Queue *q = create_queue();
    int *state = (int *) malloc(sizeof(int) * g->n_vertex);
    for (int i = 0; i < g->n_vertex; i++)
    {
        state[i] = 0;
    }
    state[sommet_depart] = 1;
    enqueue(q, sommet_depart);
    while(!is_empty(q))
    {
        int sommet = dequeue(q);
        printf("Sommet %d is visited\n", sommet);
        for (int i = 0 ; i < g->n_vertex ; i++)
        {
            if (g->matrix[sommet][i] != 0 && state[i] == 0)
            {
                state[i] = 1;
                enqueue(q, i);
            }
        }
    }
}