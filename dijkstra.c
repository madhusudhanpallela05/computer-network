DIJKSTRA
 #include <stdio.h>
 #define INF 9999998
 int main() {
    int n, src;
    printf("n: ");
    scanf("%d", &n);
    int g[n][n], dist[n], vis[n];
    printf("adj:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
            if (i != j && g[i][j] == 0)
                g[i][j] = INF;
        }
    printf("source (0..%d): ", n - 1);
    scanf("%d", &src);
    for (int i = 0; i < n; i++) {
        dist[i] = g[src][i];
        vis[i] = 0;
    }
    dist[src] = 0;
    for (int k = 0; k < n; k++) {
        int u = -1, best = INF;
        for (int i = 0; i < n; i++)
            if (!vis[i] && dist[i] < best) {
                best = dist[i];
                u = i;
            }
        if (u < 0)
            break;
        vis[u] = 1;
        for (int v = 0; v < n; v++)
            if (dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
    }
    printf("dist from %d: ", src);
    for (int i = 0; i < n; i++)
        printf("%d ", dist[i] >= INF ? 999 : dist[i]);
}
OUTPUT
n: 5
adj:
0 5 1 0 8
5 0 0 0 4
1 0 0 4 0
0 0 4 0 3
8 4 0 3 0
source (0..4): 0
dist from 0: 0 5 1 5 8 
