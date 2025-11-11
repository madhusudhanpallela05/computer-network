#include <stdio.h>
#define INF 999
#define MAX 20

struct RoutingTable
{
    int dist[MAX];
    int nextHop[MAX];
};

void main()
{
    int n;
    int cost[MAX][MAX];
    char nodes[MAX][20];
    struct RoutingTable rt[MAX];

    printf("Enter number of nodes (hosts/routers): ");
    scanf("%d", &n);

    printf("Enter node names (e.g., H1, H2):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Node %d: ", i + 1);
        scanf("%19s", nodes[i]);
    }

    printf("\nEnter adjacency matrix (delay cost, INF=999, 0 for self):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    }

    // Initialize routing tables
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rt[i].dist[j] = cost[i][j];
            if (cost[i][j] != INF && i != j)
                rt[i].nextHop[j] = j;
            else
                rt[i].nextHop[j] = -1;
        }
    }

    int updated;
    do
    {
        updated = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    // minimal safety guard for INF values
                    if (cost[i][k] < INF && rt[k].dist[j] < INF &&
                        rt[i].dist[j] > cost[i][k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] = cost[i][k] + rt[k].dist[j];
                        rt[i].nextHop[j] = k;
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);

    // Print Routing Tables
    for (int i = 0; i < n; i++)
    {
        printf("\nRouting Table for Node %s\n", nodes[i]);
        printf("Destination\tNextHop\t\tCost\n");
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;

            printf("%s\t\t", nodes[j]);
            if (rt[i].dist[j] == INF || rt[i].nextHop[j] == -1)
            {
                printf("-\t\tINF\n");
            }
            else
            {
                printf("%s\t\t%d\n", nodes[rt[i].nextHop[j]], rt[i].dist[j]);
            }
        }
    }
}
