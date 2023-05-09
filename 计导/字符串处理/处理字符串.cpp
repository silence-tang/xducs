#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std; 
int main()
{
	char str[100],str1[100],str2[100];
	int len,j,k,i;
	gets(str);
	len = strlen(str);
	for (i=1,j=0,k=0;i<len;i++)
	{
		if (str[i] > str[0])
			str1[j++] = str[i];
		if (str[i] <= str[0])
			str2[k++] = str[i];
	}
	sort(str2,str2+k);
    for(i=0;i<j;i++)
    {
    	printf("%c",str1[i]);
	}
	printf("%c",str[0]);
	for(i=0;i<k;i++)
    {
    	printf("%c",str2[i]);
	}
	return 0;
}//输入样例	
//aQWERsdfg7654!@#$hjklTUIO3210X98aY

//输出样例	
//sdfghjkla!#$0123456789@EIOQRTUWXYa
