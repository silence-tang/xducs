#include<stdio.h>
#include<ctype.h>
int main()
{
  char a[50];
  int i,j,c,n,m;
  gets(a);
  for(i=0;(c=a[i])!='\0';++i)
  {
	  if(isalpha(c))//如果c是字母 
	  {
	    m=a[i];++i;c=a[i];
		if(isdigit(c))//如果c是十进制字符 
		{
 			for(n=0;isdigit(c)&&c!='\0';c=a[i])
			{++i;n=10*n+(c-'0');}
		    if(n>=3)  
				for(j=0;j<n;++j)printf("%c",m );
			else
				printf("%c%c",m,a[i-1]);
			--i;
			
		}
	  else{
		--i;
		printf("%c",a[i]);}
        }
	  else
	  printf("%c",a[i]);
  }
  printf("\n");
return 0;
}
