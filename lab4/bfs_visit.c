// uses BFS to find nodes which are visitable

#include <stdio.h>

int stack[100];
int top = -1;

void stack_push(int ele) {
    stack[++top] = ele;
}

int stack_pop() {
    return stack[top--];
}

int stack_empty() {
    return top == -1;
}

void bfs(int size, int adjacency[][100], int starting_node, int visited_nodes[]) {
    
    stack_push(starting_node);
    
    while (!stack_empty()) {
        
        int visiting = stack_pop();
        visited_nodes[visiting] = 1;
        
        for (int i = 0; i < size; i++) {
            if (adjacency[visiting][i] == 1 && visited_nodes[i] != 1) {
                stack_push(i);
            }
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
    for (int i = 0; i < size; i++) {
        visited_nodes[i] = 0;
    }
    
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
1 1 0 1 0
1 0 1 0 0
0 0 1 1 0
Enter starting position: 1
Nodes visitable from 1: 1 2 3 4

*/
