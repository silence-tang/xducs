#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
    char str0[100],str[100],lwrstr0[100],lwrstr[100];
    int flag,n,i; 
    gets(str0);
    scanf("%d",&flag);
	scanf("%d",&n);
    strcpy(lwrstr0,str0);
    strlwr(lwrstr0);            //获得str的小写字符串，放在变量lwrstr0中
    for(i=0;i<n;i++) 
	{
        gets(str);
        if(flag == 0)    // 大小写无关
		{      
            strcpy(lwrstr,str); strlwr(lwrstr);
            if(strstr(lwrstr,lwrstr0))
            puts(str);
        } 
		else    // flag = 1，大小写有关
		{ 
            if(strstr(str,str0))
            puts(str);
        }
    }
     return 0;
}
