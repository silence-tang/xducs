#include<stdio.h>

int main()
{
	int n,i,j,flag1=1,flag2 = 1;
	int a[200][200]={};
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
	for(i=0;i<n;i++)
		if(a[i][i]!=1)
			flag1=0;//�����Է��� 
	
	for(i=0;i<n;i++)
		if(a[i][i]!=0)
			flag2=0;//���Ƿ��Է���
	if(flag1==1)
		printf("The matrix is reflexive.");
	if(flag2==1)
		printf("The matrix is irreflexive.");
	if(flag1==0&&flag2==0)
		printf("The matrix is not irreflexive or reflexive.");
	return 0;
}
