#include <stdio.h>
int main()
{
	int a,b,c,d,x,y,z,e,f,g;
	
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
    if(a<=b)
    {a=a;
     b=b;}
    else
	{x=a;
	 a=b;
	 b=x;}
	 
	if(b<=c)
    {b=b;
     c=c;}
    else
	{y=b;
	 b=c;
	 c=y;}
	 
	if(c<=d)
    {c=c;
     d=d;}
    else
	{z=c;
	 c=d;
	 d=z;}
	 
	if(a<=b)
    {a=a;
     b=b;}
    else
	{e=a;
	 a=b;
	 b=e;}
	 
	if(b<=c)
    {b=b;
     c=c;}
    else
	{f=b;
	 b=c;
	 c=f;}
	 
	if(a<=b)
    {a=a;
     b=b;}
    else
	{g=a;
	 a=b;
	 b=g;}
	 

	printf("%d %d %d %d",a,b,c,d);
	 
	 return 0;
	 
}
