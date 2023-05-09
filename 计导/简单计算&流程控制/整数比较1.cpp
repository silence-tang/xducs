# include<stdio.h>
int main()
{
	int a,b,max,min,c,i,d;
	
	scanf("%d %d",&a,&b);
	
	max = (a>=b) ? a : b;
	
	min = (a<=b) ? a : b;

    d = max % 10;
    for(i=1;i<=10000;i++)
    {
    	d = d % 10;
        if(d<10)
        {
        printf("%d ",d);
		}
        break;	
	}
    
    printf("%d",min*min);
    
    return 0;

 } 
