#include <stdio.h>

int main() {
    int m, n, k, i, j, l;
    scanf("%d%d%d", &m, &n, &k);
    int x[m][n], y[n][k], z[m][k];
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &x[i][j]);
    for(i = 0; i < n; i++)
        for(j = 0; j < k; j++)
            scanf("%d", &y[i][j]);
    for(i = 0; i < m; i++)
        for(j = 0; j < k; j++) {
            z[i][j] = 0;
            for(l = 0; l < n; l++)
                z[i][j] += x[i][l]*y[l][j];
        }
    for(i = 0; i < m; i++) {
        for(j = 0; j < k; j++)
            printf("%d ", z[i][j]);
        printf("\n");
    }
    return 0;
}