typedef struct _graph
{
    int n_vertex;
    int n_edge;
    int **matrix;
} Graph;

void init_graph(Graph *g);
void input_graph(Graph *g, int is_directed);
void save_graph(Graph *g, char *filename);
void load_graph(Graph *g, char *filename);
void print_graph(Graph *g);
