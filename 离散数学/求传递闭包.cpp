#include <stdio.h>
#include <stdlib.h>
#define N 100

int main()
{
	int b[N][N] = {0};
	int i, j, k, m;
	scanf("%d", &m);
	for (i = 0;i < m;i++)
		for (j = 0;j < m;j++)
			scanf("%d", &b[i][j]);
			
	for (i = 0;i < m;i++)
	{
		for (j = 0;j < m;j++)
		{
			for (k = 0;k < m;k++)
			{
				if (b[i][j]==1 && b[j][k]==1)
				{
					b[i][k] = 1;
				}
			}
		}
	}
	for (i = 0;i < m;i++)
	{
		for (j = 0;j < m;j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
