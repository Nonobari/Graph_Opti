#include <stdio.h>
#include <stdlib.h>
#include "graph.h"



int main()
{
    Graph g;
    int n_vertex = 6;
    init_graph(&g);
    input_graph(&g, 0);
    save_graph(&g,  "graph.txt");
    printf("ok\n");
    return 0;
}