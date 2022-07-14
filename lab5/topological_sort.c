#include <stdio.h>
#include <stdbool.h>

#define MAX_ARR 20

int main() {
    
    bool adjacency_matrix[MAX_ARR][MAX_ARR];
    int in_degree[MAX_ARR] = { 0 };
    bool is_visited[MAX_ARR] = { 0 };
    
    int no_vertices;
    
    printf("Enter number of vertices: ");
    scanf("%d", &no_vertices);
    
    if (no_vertices > MAX_ARR) {
        printf("Entered Value Too Big.\n");
        return -1;
    }
    
    printf("Enter the Adjacency Matrix:\n");
    for (int i = 0; i < no_vertices; i++) {
        for (int j = 0; j < no_vertices; j++) {
            int val;
            scanf("%d", &val);
            if (val != 0 && val != 1) {
                printf("Invalid Value.\n");
                return -1;
            }
            adjacency_matrix[i][j] = val;
        }
    }
    
    for (int i = 0; i < no_vertices; i++) {
        for (int j = 0; j < no_vertices; j++) {
            in_degree[i] = in_degree[i] + adjacency_matrix[j][i];
        }
    }
    
    int topological_order[MAX_ARR];
    int topo_size = 0;
    
    while (topo_size < no_vertices) {
        
        for (int i = 0; i < no_vertices; i++) {
            
            if (!is_visited[i] && in_degree[i] == 0) {
                topological_order[topo_size++] = (i+1);
                is_visited[i] = true;
            }
            
            for (int j = 0; j < no_vertices; j++) {
                
                if (adjacency_matrix[j][i]) {
                    in_degree[i]--;
                }
            }
        }
    }
    
    printf("Topological Order:");
    for (int i = 0; i < topo_size; i++) {
        printf(" %d", topological_order[i]);
    }
    printf("\n");
    
    return 0;
}
