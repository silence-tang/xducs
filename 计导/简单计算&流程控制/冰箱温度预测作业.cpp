# include<stdio.h>

int main()

{
   int a,b;
   
   double t,T;
   
   scanf("%d %d", &a,&b);
   
   
   t = a + b*0.01*100/60;
   
   T = 4*t*t/(t+2)-20;
   
   printf("����ϵ�󾭹�%.2fСʱ����¶�Ϊ%.2f���϶�",t,T);
   
   
   return 0;

} 
