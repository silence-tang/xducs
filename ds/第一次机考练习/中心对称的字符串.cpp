#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,n,flag1=0,flag2=0;
	scanf("%d",&n);
	char str[n];
	scanf("%s",str);
	if(n%2==0)
	{
		for(i=0;i<=(n-2)/2;i++)
		{
			if(str[i]!=str[n-1-i])
			{
				flag1 = 1;
				break;
			}
		}
		
		if(flag1==1)
			printf("NO");
		else
			printf("YES");
	}
	
	if(n%2==1)
	{
		for(i=0;i<=(n-3)/2;i++)
		{
			if(str[i]!=str[n-1-i])
			{
				flag2 = 1;
				break;
			}
		}
		
		if(flag2==1)
			printf("NO");
		else
			printf("YES");
	}
	return 0;
}
