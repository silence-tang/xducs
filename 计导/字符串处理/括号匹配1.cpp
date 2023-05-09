#include<stdio.h>
#include<string.h>
int main()
{
	int al=0,bl=0,cl=0,ar=0,br=0,cr=0,i,flag=0;
	char str[55];
	gets(str);
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]=='(') al++;
		if (str[i]=='[') bl++;
		if (str[i]=='{') cl++;
		if (str[i]==')') ar++;
	    if (str[i]==']') br++;
	    if (str[i]=='}') cr++;
	}//求出每种括号的左右括号的个数 
	if(al==ar&&bl==br&&cl==cr) printf("yes");
    else printf("no");
	return 0;
}
