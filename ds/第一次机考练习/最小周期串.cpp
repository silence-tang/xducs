#include <iostream>//暴力求最小周期
#include <cstdio>
#include <cstring>
using namespace std;
 
int main()
{
	int i,j,len; 
    char a[100];
    scanf("%s",a);
    len=strlen(a);
	for(j=1;j<=len;j++)
	{   
		if(!(len%j))
        {
        	for(i=0;i<len;i++)
            {
                if(a[i]!=a[i%j])
                    break;
                if(i == len-1)
                {
                    printf("%d",j);
                    j = len+1;
                }
            }
		}	
    }
	
    return 0;
}
