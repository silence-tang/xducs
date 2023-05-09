#include<cstring>
#include<map>
#include<stdio.h>
#include<iostream>
using namespace std;
const int N = 200005;
int pre[N], mid[N];
map<int, int> pos;
int sum[N];
char s[N*2];
bool mark[N];
int n = 0;

int Find(int x)
{
    for(int i = 1; i <= n / 2; ++i)
	{
        if(mid[i] == x && mark[i] == 0)
		{
            mark[i] = 1;
            return i;
        }
    }
}

void gao(int l1, int r1, int l2, int r2)
{
    if(l1 > r1) return;
    if(l1 == r1)
	{
        printf("%d ", 0);
        return;
    }
    int rt = pre[l1];
    int ky = Find(rt);
    gao(l1 + 1, l1 + ky - l2 , l2, ky - 1);
    printf("%d ", sum[r2] - sum[l2 - 1] - rt);
    gao(l1 + ky - l2 + 1, r1, ky + 1, r2);
}
void tq()
{
    int len = strlen(s); 
    char ch;
    int flag = 1, num = 0;
    for(int i = 0; i < len; ++i)
	{
        ch = s[i];
        if(s[i] == ' ')
		{
            num = num * flag;
            flag = 1;
            pre[++n] = num;
            num = 0;
        }
		else
		{
            if(s[i] == '-') flag = -1;
            else{
                num = num * 10 + (s[i] - '0');
            }
        }
    }
    num = num * flag;
    pre[++n] = num;
}
int main()
{   
	int num,i;
	scanf("%d",&num);
	getchar();
    cin.getline(s, 10000);
    tq();
    cin.getline(s, 10000);
    tq();
    for(int i = n / 2 + 1; i <= n; ++i) mid[i - n / 2] = pre[i];
    for(int i = 1; i <= n / 2; ++i)
	{
        pos[mid[i]] = i;
    }
    
    for(int i = 1; i <= n/2; ++i)
	{
        sum[i] = sum[i-1] + mid[i];
    }
    
    gao(1, n/2, 1, n/2);
    return 0;
}
