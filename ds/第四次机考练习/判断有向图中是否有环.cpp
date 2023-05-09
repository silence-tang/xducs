#include<stdio.h>
#include<stdlib.h>
int main()
{
    int cishu, i, j, k, n, count;
    int a[10000];
    scanf("%d", &cishu);
    for(k=0;k<cishu;k++)
    {
    	scanf("%d",&n);
    	int G[100][100]; G[100][100]=0;
    	int rudu[100] = {0};
    	int stack[100]={0}, top = -1;
    	for(i = 0; i < n; i++)
       	{
       		for(j = 0; j < n; j++)
            {
            	scanf("%d",&G[i][j]);
            	if(G[i][j]!=0)
        			rudu[j]++;
			}
		}	
		for(i = 0; i < n; i++)
    	{
        	if(rudu[i]==0)
           		stack[++top] = i; //用栈保存入度为0的结点序号 
		}
		count = 0;
    	while (top > -1)
    	{
        	i = stack[top--];
        	count++;
        	for (j = 0; j < n; j++)
        	{
            	if (G[i][j]!=0)
            	{
                	rudu[j]--;
                	if (rudu[j]==0)
                    	stack[++top] = j;
            	}
        	}
    	}
    	if (count < n)
        	a[k] = 1;
    	else
        	a[k] = 0;
	}
	
	for(i=0;i<k;i++)
		printf("%d",a[i]);
    return 0;
 }
