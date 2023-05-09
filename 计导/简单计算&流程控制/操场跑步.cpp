#include <stdio.h>

int main()
{
	
	int a[100];
	float b[100];
    for(int i=0;i<100;i++)
    {
    	scanf("%d",&a[i]);
    	if(a[i]!=0)
        { b[i]=a[i]/400.0;
        printf("%.1f ",b[i]);
	    }	
    	else break;
	}
	
   return 0;

}
