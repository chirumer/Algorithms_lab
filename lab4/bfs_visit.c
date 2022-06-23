// uses BFS to find nodes which are visitable

#include <stdio.h>

void bfs(int size, int adjacency[][100], int current_node, int visited_nodes[]) {
    visited_nodes[current_node] = 1;
    for (int i = 0; i < size; i++) {
        if (adjacency[current_node][i] == 1 && visited_nodes[i] != 1) {
            bfs(size, adjacency, i, visited_nodes);
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
    
    int start;
    printf("Enter starting position: ");
    scanf("%d", &start);
    
    int visited_nodes[100];
    bfs(size, adjacency, start-1, visited_nodes);
    
    printf("Nodes visitable from %d:", start);
    for (int i = 0; i < size; i++) {
        if (visited_nodes[i] == 1) {
            printf(" %d", i+1);
        }
    }
    printf("\n");
    
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
Enter starting position: 1
Nodes visitable from 1: 1 2 3 4 5

Enter number of nodes: 5
Enter the adjacency matrix: 
0 1 1 1 0
1 0 1 0 0
1 1 0 1 1
1 0 1 0 1
0 0 1 1 0
Enter starting position: 1
Nodes visitable from 1: 1 2 3 4 5

*/
