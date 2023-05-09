#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() 
{ char c[100],d[1000];
 int n,i,sum=0,k=0,a[100],b[100],j;
 gets(c);
 n=strlen(c);
 for(i=0;i<=99;i++)
 {a[i]=0;b[i]=0;
 }
 for(i=0;i<=n-1;i++)
 { if(isdigit(c[i])&&isdigit(c[i+1])==0)
  {
  sum=sum+1;
  a[sum-1]=c[i]-48;b[sum-1]=i;
  }
  else if(isdigit(c[i])&&isdigit(c[i+1]))
  { sum=sum+1;
  a[sum-1]=(c[i]-48)*10+c[i+1]-48;b[sum-1]=i;
  i=i+1;
  }
  else if(isdigit(c[i])==0&&isdigit(c[i+1])==0)
  { sum=sum+1;
  	a[sum-1]=1;b[sum-1]=i;
  }
 }

for(i=0;i<=sum-1;i++)
 for(j=0;j<=a[i]-1;j++)
 { if(a[i]==1)printf("%c",c[b[i]]);
 else printf("%c",c[b[i]-1]);
 }
}
