#include<stdio.h>
#include<string.h>//数字：48-57，大写字母：61-90，小写字母：97-122，其他：0-47、58-64、61-96、123-127 
int func(char c[50])
{
	int i,type,len,flag1=0,flag2=0,flag3=0,flag4=0;
	 len=strlen(c);
	  for(i=0;i<len;i++)
	  {
	   if(c[i]>=48&&c[i]<=57) flag1=1;
	    else if(c[i]>=61&&c[i]<=90) flag2=1;
	     else if(c[i]>=97&&c[i]<=122) flag3=1;
	      else flag4=1;
	  } 
	if(flag1+flag2+flag3+flag4==2) type=2;
	if(flag1+flag2+flag3+flag4==3) type=3;
	if(flag1+flag2+flag3+flag4==4) type=4;
return(type);
}

int main()
{  
   int func(char c[50]);
   char str[50]; int i,len,score;
   gets(str); len=strlen(str);
      if(len>8)
	 {
	    if(func(str)==2) score=3;
	    else if(func(str)==3) score=4;
	    else if(func(str)==4) score=5;
	    else score=2;
	 }
      else if(len<=8&&len>=1)
     {
   	     if(func(str)==2) score=2;
         else if(func(str)==3) score=3;
         else if(func(str)==4) score=4;
         else score=1;
     }
      else score=0;
     printf("%d",score);
     return 0;
}
