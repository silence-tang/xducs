#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int main()
{
	long long a[2];
	char c='1';
	string s;
	getline(cin,s);
	int n=0;
	int sign=0;
	int k=0;
	for(int i=0;i<s.length();i++)
	{
		if(isdigit(s[i]))
		{
			n=n*10+s[i]-'0';
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='%'||s[i]=='*')
		
		{
			c=s[i];
		}
		else
		{
			a[k++]=n;
			if(s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='/'||s[i-1]=='%'||s[i-1]=='*') k--;
			n=0;
		}
	}
	if(k==1) a[k++]=n;
	switch(c)
	{
		case '+':cout<<a[0]+a[1];break;
		case '-':cout<<a[0]-a[1];break;
		case '*':cout<<a[0]*a[1];break;
		case '/':cout<<a[0]/a[1];break;
		case '%':cout<<a[0]%a[1];break; 
	}
	return 0;
}
