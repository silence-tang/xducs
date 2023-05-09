#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,k,j,min;
	scanf("%d",&n);
	int a[n],b[n-1];
	for(i=0;i<=(n-1);i++)
	{
		scanf("%d",&a[i]);
		
	}
	sort(a,a+n);
	
	for(j=1;j<=(n-1);j++)
	{  
	
	 b[j]=abs(a[j]-a[j+1]);  
	
	}
	min=b[1];
	for(k=2;k<=(n-1);k++)
	{
		if(b[k]<=min)
		min=b[k];
	
	}
	
    printf("%d",min);
	return 0;
 } 
