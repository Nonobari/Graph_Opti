#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void init_graph(Graph *g)
{
    printf("Enter the number of vertex: ");
    scanf("%d", &g->n_vertex);
    printf("Enter the number of edges: ");
    scanf("%d", &g->n_edge);
    g->matrix = (int **)malloc(sizeof(int *) * g->n_vertex);
    for (int i = 0; i < g->n_vertex; i++)
    {
        g->matrix[i] = (int *)malloc(sizeof(int) * g->n_vertex);
        for (int j = 0; j < g->n_vertex; j++)
        {
            g->matrix[i][j] = 0;
        }
    }
}

void input_graph(Graph *g, int is_directed)
{
    int start, end;
    int weight;
    for (int i = 0; i < g->n_edge; i++)
    {
        printf("Enter the start, end, weight of edge %d: ", i + 1);
        if (!is_directed)
        {
            scanf("%d %d %d", &start, &end, &weight);
            g->matrix[start][end] = weight;
            g->matrix[end][start] = weight;
        }
        else
        {
            scanf("%d %d %d", &start, &end, &weight);
            g->matrix[start][end] = weight;
        }
    }
}

void save_graph(Graph *g, char *filename)
{
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Cannot open file %s\n", filename);
        return;
    }
    else
    {
        fprintf(f, "%d\n", g->n_vertex);
        fprintf(f, "%d\n", g->n_edge);
        for (int i = 0; i < g->n_vertex; i++)
        {
            for (int j = 0; j < g->n_vertex; j++)
            {
                if (g->matrix[i][j] != 0)
                {
                        fprintf(f, "%d %d %d\n", i, j, g->matrix[i][j]);
                }
            }
        }
        fclose(f);
    }
}