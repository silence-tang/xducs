#include<stdio.h>
#include<string.h>
#define N 20
int main()
{
	char str[100];
	int n,f,t;
	scanf("%d", &f);
	while (f--)
	{
		memset(str, 0, 100);   //将str用'0'表示
		scanf("%s", str);
		n = 0;
		for (int i = 0; i < 100; i++)
			if (str[i] >= '0'&&str[i] <= '9')
				n = n * 10 + str[i] - '0';
		if (n == 0)
		{
			printf("0\n");
			
		}
		else {
			for (int i = 1; i < n; i++)
				if (n%i == 0)
					t = i;
			if (t == 1)
				t = n;
			printf("%d\n", t);
		}
		
	}
	return 0;
}
