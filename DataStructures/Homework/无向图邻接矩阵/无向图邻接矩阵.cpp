#include<stdio.h>

const int n = 8;
const int e = 10;
typedef char vextype;
typedef int adjtype;
typedef struct {
    vextype vexs[n];
    adjtype arcs[n][n];
} graph;

graph *g = new graph;
void creatgraph();
void dfs(int);
void dfsa(int);
int visited[n];

int main() {
    creatgraph();
    int i;
    while (1) {
        for (i = 0; i < n; i++)
            visited[i] = 0;
        printf("\n输入出发点序号（0-7），输入-1结束：");
        scanf("%d", &i);
        if (i == -1) break;
        dfsa(i);
    }
    return 0;
}

//建立无向图邻接矩阵
void creatgraph() {
    int i, j, k;
    char ch;
    printf("输入8个顶点的字符数据信息:\n");
    for (i = 0; i < n; i++)
        if ((ch = getchar()) != '\n') g->vexs[i] = ch;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g->arcs[i][j] = 0;
    printf("输入10条边的起、终点i,j:\n");
    for (k = 0; k < e; k++) {
        scanf("%d,%d", &i, &j); // 顶点序号从0开始
        g->arcs[i][j] = g->arcs[j][i] = 1;
    }
}

//添加深度优先搜索遍历算法
void dfsa(int v) {
    printf("%c ", g->vexs[v]); // 访问顶点
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (g->arcs[v][i] == 1 && !visited[i]) {
            dfsa(i); // 对未访问的邻接顶点递归调用
        }
    }
}

