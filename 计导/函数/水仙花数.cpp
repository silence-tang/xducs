#include<stdio.h>
int function(int a,int b)
{
    int i,t,k,t1,r,sum,w,m,p,q; int result=0;
	  
	a=( a<=b ? a : b );
	b=( a<=b ? b : a );
	
    for(i=a;i<=b;i++)
    {  
        if(i/100==0)
        continue;
        t1=t=i;
        
        for(k=1;t/10!=0;++k)
        {
             t=t/10;     
	    }                 // k��ʾλ��
		    
	         sum=0;       //Ҫ����ĳ��ѭ����ʹ�ñ��������ʼ��������д�ڴ�ѭ��������ѭ����������Ҳ���������ѭ���ڣ� 
        for(r=1;r<=k;r++)
        {    
           w=t1%10;  q=w;
           t1=t1/10; 
           for(p=1;p<k;p++)
           {  
		     q=q*w;
		   }
		     sum+=q;
	    }
	
	    if(sum==i)
        result++;
        else continue;
   }
	      return(result);
}

int main()

	{
		int a,b,result;
    	int function(int a,int b);
		scanf("%d %d",&a,&b);
	    result=function(a,b);
	    printf("%d",result);
	    
		return 0;
	}
