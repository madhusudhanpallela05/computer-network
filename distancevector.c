DISTANCE VECTOR 
#include <stdio.h>
 #define INF 999
 int main() {
    int n, cost[10][10], dist[10][10];
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = cost[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    printf("\nFinal Distance Table:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < n; j++)
            printf("%d ", dist[i][j]);
        printf("\n");
    }
    return 0;
 }
OUTPUT:
Enter number of nodes: 4
Enter cost matrix:
0 5 1 999
5 0 3 2
1 3 0 2
999 2 2 0

Final Distance Table:
Node 0: 0 4 1 3 
Node 1: 4 0 3 2 
Node 2: 1 3 0 2 
Node 3: 3 2 2 0
