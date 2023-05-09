#include<stdio.h>
#include<stdlib.h>
#define INF 65535
typedef struct
{
    int edges[100][100];
    int n, e;
}MGraph;

void Floyd(MGraph *g, int A[][100], int path[100][100])
{
    int i, j, k;
    for (i = 0; i < g->n; i++)
    {
        for (j = 0; j < g->n; j++)
        {
            A[i][j] = g->edges[i][j];
            if ( g->edges[i][j] < INF)
                path[i][j] = j;
            else
                path[i][j] = -1;
        }
    }
    for (k = 0; k < g->n; k++)
    {
        for (i = 0; i < g->n; i++)
        {
            for (j = 0; j < g->n; j++)
            {
                if (A[i][k] + A[k][j] < A[i][j])
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
    int i, j, k, count;
	int indegree[100] = {0};
    int stack[100], top = -1;
    int A[100][100],path[100][100];
    MGraph* g = (MGraph*)malloc(sizeof(MGraph));
    scanf("%d", &g->n);
    for(i = 0; i < g->n; i++)
    {
    	for(j = 0; j < g->n; j++)
        {
        	scanf("%d", &g->edges[i][j]);
            if(g->edges[i][j]==0)
            	g->edges[i][j]=INF;
            else
            	g->edges[i][j]=-1*g->edges[i][j];
            if(g->edges[i][j]!=INF)
            	indegree[j]++;
		}
	}
	
    Floyd(g, A, path);
    
    for(i = 0; i < g->n; i++)
    {
        if(!indegree[i])
            stack[++top] = i;
    }
    count = 0;
    while(top > -1)
    {
        i = stack[top--];
        count++;
        for(j = 0; j < g->n; j++)
        {
            if(g->edges[i][j]!=INF)
            {
                indegree[j]--;
                if (!indegree[j])
                    stack[++top] = j;
            }
        }
    }
    
    if(count < g->n)
        printf("NO");
    else
        printf("%d",-A[0][g->n-1]);
	return 0;
}
