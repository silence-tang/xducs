#include <stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,p,q,a[1000],b[1000],k1,k2;
	scanf("%d\n",&n);
	scanf("%d",&p);
	for(i=0;i<p;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d",&b[i]);
	}
	sort(a,a+p);sort(b,b+q);
	for(i=1;i<p-1;i++)
	{
		if(a[i]-a[i-1]==a[i+1]-a[i]) k1=1;
		else k1=0;
	}
	for(i=1;i<q-1;i++)
	{
		if(b[i]-b[i-1]==b[i+1]-b[i]) k2=1;
		else k2=0;
	}
	if(k1==1&&k2==1) printf("%d\n%d",a[1]-a[0],b[1]-b[0]);
	if(k1==1&&k2==0) printf("%d\nno",a[1]-a[0]);
	if(k1==0&&k2==1) printf("no\n%d",b[1]-b[0]);
	if(k1==0&&k2==0) printf("no\nno");
  return 0;
 } 
