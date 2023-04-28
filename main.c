#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "algo.h"

void menu(Graph *g)
{
    int choice;
    do
    {
        printf("\n0. Exit\n");
        printf("1. Init graph\n");
        printf("2. Input graph\n");
        printf("3. Save graph\n");
        printf("4. Load graph\n");
        printf("5. Print graph\n");
        printf("6. Check if graph has eulerian path\n");
        printf("7. Check if graph has eulerian cycle\n");
        printf("8. Depth first search\n");
        printf("9. Breadth first search\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            break;
        case 1:
            init_graph(g);
            break;
        case 2:
            input_graph(g, 0);
            break;
        case 3:
            save_graph(g, "graph.txt");
            break;
        case 4:
            load_graph(g, "graph.txt");
            break;
        case 5:
            print_graph(g);
            break;
        case 6:
            if (parcours_eulerien(g))
                printf("The graph admits an Eulerian path\n");
            else
                printf("The graph doesn't admit an Eulerian path\n");
            break;
        case 7:
            if (cycle_eulerien(g))
                printf("The graph admits an Eulerian cycle\n");
            else
                printf("The graph doesn't admit an Eulerian cycle\n");
            break;
        case 8:
            parcours_profondeur(g, 0);
            break;
        case 9:
            parcours_largeur(g, 0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 0);
}

int main()
{
    Graph g;
    menu(&g);
    return 0;
}