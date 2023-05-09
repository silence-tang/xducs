# include<stdio.h>

int main()

{
   int a,b;
   
   double t,T;
   
   scanf("%d %d", &a,&b);
   
   
   t = a + b*0.01*100/60;
   
   T = 4*t*t/(t+2)-20;
   
   printf("冰箱断电后经过%.2f小时后的温度为%.2f摄氏度",t,T);
   
   
   return 0;

} 
