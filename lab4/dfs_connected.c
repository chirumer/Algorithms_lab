// uses DFS to check if graph is connected

#include <stdio.h>

void dfs(int size, int adjacency[][100], int current_node, int visited_nodes[]) {
    visited_nodes[current_node] = 1;
    for (int i = 0; i < size; i++) {
        if (adjacency[current_node][i] == 1 && visited_nodes[i] != 1) {
            dfs(size, adjacency, i, visited_nodes);
        }
    }
}

int main() {
    
    int size;
    printf("Enter number of nodes: ");
    scanf("%d", &size);
    
    int adjacency[100][100];
    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &adjacency[i][j]);
        }
    }
    
    int visited_nodes[100];
    for (int i = 0; i < size; i++) {
        visited_nodes[i] = 0;
    }
    
    dfs(size, adjacency, 0, visited_nodes);
    
    int is_connected = 1;
    for (int i = 0; i < size; i++) {
        if (visited_nodes[i] != 1) {
            is_connected = 0;
        }
    }
    
    if (is_connected == 1) {
        printf("Graph is connected.\n");
    }
    else {
        printf("Graph is not connected.\n");
    }
    
    return 0;
}


/*

Sample Output:

Enter number of nodes: 5
Enter the adjacency matrix: 
0 1 1 1 0
1 0 1 0 0
1 1 0 1 1 
1 0 1 0 1
0 0 1 1 0
Graph is connected.

Enter number of nodes: 5
Enter the adjacency matrix: 
0 1 1 1 0
1 0 1 0 0
1 1 0 1 0
1 0 1 0 0
0 0 1 1 0
Graph is not connected.

*/
