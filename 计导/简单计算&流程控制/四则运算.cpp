#include<stdio.h>

int main()
{
   int a,b,c;
   char op;
   scanf("%d%c%d",&a,&op,&b);
   if(op=='+')c=a+b;
   
   else if (op=='-')c=a-b;
   else if (op=='*')c=a*b;
   else if (op=='/')c=a/b;
   else(op=='%'); 
   c=a%b;
   
   printf("%d%c%d=%d\n",a,op,b,c);
   return 0;
 
 
}
