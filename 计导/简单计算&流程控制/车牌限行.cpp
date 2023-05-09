# include <stdio.h>
int main()
{
	int a,b,n,i,m,x; //a 表示星期，b表示雾霾指数，n表示车牌//
	int num=0;
	scanf("%d %d %d",&a,&b,&n);
    m=n;
    while(n)
	{
        num++;
        n/=10;
    } 

	    x=num;
	for(i=1;i<=(x-1);i++)    
	  {
		m=m%10;//此时m表示末位数 
	  }  
	  
	if(a==6||a==7) printf("%d no",m); 
	
	if(a==1||a==2||a==3||a==4||a==5)
	{
	   if(b<200) printf("%d no",m);
	   else if(b>=200&&b<400)
	   {
	   	if(a==1)
		   {if(m==1||m==6) printf("%d yes",m);
		   	else printf("%d no",m);
			} 
	   	if(a==2)
		   {if(m==2||m==7) printf("%d yes",m);
		   	else printf("%d no",m);
			} 
		if(a==3)
		   {if(m==3||m==8) printf("%d yes",m);
		   	else printf("%d no",m);
			}
		if(a==4)
		   {if(m==4||m==9) printf("%d yes",m);
		   	else printf("%d no",m);
			}
		if(a==5)
		   {if(m==5||m==0) printf("%d yes",m);
		   	else printf("%d no",m);
			} 
	   }
	    else
	    {
		if(a==1||a==3||a==5)
		   {if(m==1||m==3||m==5||m==7||m==9) printf("%d yes",m);
		   	else printf("%d no",m);
	   	   }
		   	
		if(a==2||a==4)
		   {if(m==0||m==2||m==4||m==6||m==8) printf("%d yes",m);
		   	else printf("%d no",m); 	
		   } 
	    }
     }
	return 0;
	
	
}
