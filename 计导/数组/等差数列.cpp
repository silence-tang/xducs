#include stdio.h
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,a[1000],b[1000],k;
	scanf("%d",&n);
    for(i=0;i<n;i++)
	 scanf("%d",&a[i]);
	  sort(a,a+n);
	for(i=1;i<n-1;i++)
	{
		if(a[i]-a[i-1]==a[i+1]-a[i]) k=1;
		else k=0;
	}
	if(k==1) printf("%d",a[1]-a[0]);
	else printf("no");
  return 0;
 } 
