#include<stdio.h>
#include<string.h>
int main()
{
  int m,n=0;char a[100],b[100];
  while(1)  //��������ַ�����Ϊ***end***ʱ
{     
      gets(a);
      if(strcmp(a,"***end***")==0)
      break;
      
      m=strlen(a); 
	  if(m>n)
	  { n=m;
	    strcpy(b,a);
	  }
/*abce
abdf dlfd
***end*** */
  }
  printf("%d\n%s\n",n,b);
  return 0;
}
