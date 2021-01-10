#include<stdio.h>
#include <stdlib.h>

#define NODES 9 /* ノードの数 */
#define INF 999 /* 無限大の距離 */

int matrix[NODES][NODES]; /* 隣接行列 */
int o = 0;
int distance[NODES][NODES];

void warshall_floyd(void) {
    int i, j, k;
    for(i = 0; i < NODES; i++)
    for(j = 0; j < NODES; j++)
    distance[i][j] = matrix[i][j];
    for(k = 0; k < NODES; k++)
    for(i = 0; i < NODES; i++)
    for(j = 0; j < NODES; j++)
    if(distance[i][j] > distance[i][k] + distance[k][j])
        distance[i][j] = distance[i][k] + distance[k][j];
}

int main() {
    int u, v; /* ループ用　*/
    int weight; /* 辺の重さ */
    FILE *fp; /* 読み込み用ファイルポインタ*/
    
    /* 隣接行列の全ての要素を無限大にする */
    for (u = 0; u < NODES; u++)
    for (v = 0; v < NODES; v++)
    matrix[u][v] = INF;
    
    /* ファイルデータのオープン */
    if ((fp = fopen ("/Users/labd/Documents/11(5)/11(5)/graph2.dat", "r")) == NULL) {
        fprintf (stderr, "File not found: graph2.dat \n");
        exit (1);
    }
    
    /* ファイルからデータを読み込む　*/
    while (fscanf (fp, "%d %d %d", &u, &v, &weight) != EOF) {
    matrix[u][v] = weight; /* 辺を登録する */
    matrix[v][u] = weight;
    }
    fclose(fp);
    
    warshall_floyd();
    
    for(int i = 0; i < 9; i++){
        for(int j = 0;j < 9; j++)printf("%3d", distance[i][j]);
        printf("\n");
    }
    return 0;
}

