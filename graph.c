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
    printf("Graph successfully initialised\n");
}

void input_graph(Graph *g, int is_directed)
{
    int start, end;
    int weight;
    for (int i = 0; i < g->n_edge; i++)
    {
        printf("Enter the start, end, weight of edge %d: ", i+1);
        if (!is_directed)
        {
            scanf("%d %d %d", &start, &end, &weight);
            if (start >= g->n_vertex || end >= g->n_vertex)
            {
                printf("\nError : Invalid edge, vertex index must begin at 0\n");
                i--;
                continue;
            }
            else
            {
                g->matrix[start][end] = weight;
                g->matrix[end][start] = weight;
            }
            
        }
        else
        {
            scanf("%d %d %d", &start, &end, &weight);
            if (start >= g->n_vertex || end >= g->n_vertex)
            {
                printf("\nError : Invalid edge, vertex index must begin at 0\n");
                i--;
                continue;
            }
            else
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

void load_graph(Graph *g, char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Cannot open file %s\n", filename);
        return;
    }
    else
    {
        //initialisation du graphe
        fscanf(f, "%d", &g->n_vertex);
        fscanf(f, "%d", &g->n_edge);
        g->matrix = (int **)malloc(sizeof(int *) * g->n_vertex);
        for (int i = 0; i < g->n_vertex; i++)
        {
            g->matrix[i] = (int *)malloc(sizeof(int) * g->n_vertex);
            for (int j = 0; j < g->n_vertex; j++)
            {
                g->matrix[i][j] = 0;
            }
        }
        int start, end, weight;
        while(fscanf(f, "%d %d %d", &start, &end, &weight)!=EOF)
        {
            g->matrix[start][end] = weight;
        }
        fclose(f);
    }
}

void print_graph(Graph *g)
{
    printf("Number of vertex: %d\n", g->n_vertex);
    printf("Number of edges: %d\n", g->n_edge);
    for (int i = 0; i < g->n_vertex; i++)
    {
        for (int j = 0; j < g->n_vertex; j++)
        {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

int parcours_eulerien(Graph *g)
//renvoi 1 si le graphe admet un parcours eulerien (on peut le parcourir sans lever le stylo)  renvoi 0 sinon.
{
    int *degres = (int *) malloc(sizeof(int) * g->n_vertex);
    int somme = 0;
    for (int i = 0; i < g->n_vertex; i++)
    {
        degres[i] = 0;
        for (int j = 0; j < g->n_vertex; j++)
        {
            if (g->matrix[i][j] != 0)
            {
                degres[i]++;
                somme++;
            }
        }
    }
    int n_vertex_pair = 0;
    for (int i = 0; i < g->n_vertex; i++)
    {
        if (degres[i] % 2 == 0)
            n_vertex_pair++;
    }
    if (n_vertex_pair >= g->n_vertex - 2)
        return 1;
    else
        return 0;
}

int cycle_eulerien(Graph *g)
//renvoi 1 si le graphe admet un cycle eulerien (on peut le parcourir sans lever le stylo et retourner au sommet de depart)  renvoi 0 sinon
{
    int *degres = (int *) malloc(sizeof(int) * g->n_vertex);
    int somme = 0;
    for (int i = 0; i < g->n_vertex; i++)
    {
        degres[i] = 0;
        for (int j = 0; j < g->n_vertex; j++)
        {
            if (g->matrix[i][j] != 0)
            {
                degres[i]++;
                somme++;
            }
        }
    }
    int n_vertex_pair = 0;
    for (int i = 0; i < g->n_vertex; i++)
    {
        if (degres[i] % 2 == 0)
            n_vertex_pair++;
    }
    if (n_vertex_pair == g->n_vertex)
        return 1;
    else
        return 0;
}
