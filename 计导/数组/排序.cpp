#include <stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i,k=-1,j=-1,n,a[10000],b[10000],c[10000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	   scanf("%d",&a[i]);	
    } 
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
     	if(a[i]%2==0)
     	{ k++;
     	  b[k]=a[i];
		}
	}
    for(i=0;i<n;i++)
    {
     	if(a[i]%2==1)
     	{ j++;
     	  c[j]=a[i];
		}
	}
   for(i=k;i>=0;i--) printf("%d ",b[i]);
   for(i=j;i>=0;i--) printf("%d ",c[i]);
   return 0;
}
