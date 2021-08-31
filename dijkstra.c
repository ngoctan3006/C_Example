#include <stdio.h>
#include <stdlib.h>

#define INFINITY 999999

int dijsktra(int, int[][100], int, int);
void addEdge(int[][100], int, int, int);
void intrev(int*, int);

int main() {
    int graph[100][100] = {INFINITY};
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 1, 4, 3);
    addEdge(graph, 2, 3, 6);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 2, 5, 5);
    addEdge(graph, 3, 4, 5);
    addEdge(graph, 3, 6, 4);
    addEdge(graph, 3, 7, 5);
    addEdge(graph, 4, 5, 5);
    addEdge(graph, 4, 6, 4);
    addEdge(graph, 5, 6, 5);
    addEdge(graph, 5, 8, 7);
    addEdge(graph, 6, 7, 3);
    addEdge(graph, 6, 8, 8);
    addEdge(graph, 7, 8, 9);
    int w = dijsktra(9, graph, 1, 8);
    printf("\n%d", w);
    return 0;
}

void addEdge(int g[][100], int v1, int v2, int weight) {
    g[v1][v2] = weight;
    g[v2][v1] = weight;
}

void intrev(int *path, int n) {
    int temp[100], i;
    for(i = 0; i < n; i++) temp[i] = path[n-1-i];
    for(i = 0; i < n; i++) path[i] = temp[i];
}

int dijsktra(int n, int cost[][100], int source, int target) {
    int dist[100], prev[100], i, m, min, start, d, j;
    int selected[100];
    for(i = 0; i < 100; i++)
    	selected[i] = 0;
    int path[100];
    for(i = 1; i < n; i++) {
        dist[i] = INFINITY;
        prev[i] = -1;
    }
    start = source;
    selected[start] = 1;
    dist[start] = 0;
    while(selected[target] == 0) {
        min = INFINITY;
        m = 0;
        for(i = 1; i < n; i++) {
            d = dist[start] + cost[start][i];
            if(d < dist[i] && selected[i] == 0) {
                dist[i] = d;
                prev[i] = start;
            }
            if(min > dist[i] && selected[i] == 0) {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 0;
    while(start != -1) {
        path[j++] = start ;// + 65;
	//cout << path[j] << endl;
        start = prev[start];
    }
    //path[j]='\0';
    
    intrev(path, j);
    
    for (i = 0; i < j; i++)
    	printf("%d ", path[i]);
    printf("\n");
    return dist[target];
}