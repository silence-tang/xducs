#include<stdio.h>
#include<stdlib.h>
#define INF 10000
typedef struct MGraph
{
    int edges[100][100];//存放边的权重 
    int n, e;           //结点个数和边的个数 
};

void Floyd(MGraph *g, int A[][100], int path[100][100])
{
    int i, j, k;
    for(i = 0; i < g->n; i++)
    {
        for(j = 0; j < g->n; j++)
        {
            A[i][j] = g->edges[i][j];
            if(g->edges[i][j] < INF)
                path[i][j] = j;
            else
                path[i][j] = -1;
        }
    }
    for(k = 0; k < g->n; k++)
    {
        for(i = 0; i < g->n; i++)
        {
            for(j = 0; j < g->n; j++)
            {
                if(A[i][k] + A[k][j] < A[i][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
}

int main()
{
    int i, j, k;
    int m, n;
    int A[100][100],path[100][100];
    MGraph* g = (MGraph*)malloc(sizeof(MGraph));
    scanf("%d", &g->n);
    for (i = 0; i < g->n; i++)
        for (j = 0; j < g->n; j++)
            scanf("%d", &g->edges[i][j]);
            
    Floyd(g, A, path);

    while(scanf("%d %d",&m,&n) && (m!=-1||n!=-1))
    {
        k = path[m][n];
        if (k < 0)
        {
            printf("NO\n");
            continue;
        }
        printf("%d\n", A[m][n]);
        printf("%d ", m);
        while (k != n)
        {
            printf("%d ", k);
            k = path[k][n];
        }
        printf("%d",n);
        printf("\n");
    }
    return 0;
}
