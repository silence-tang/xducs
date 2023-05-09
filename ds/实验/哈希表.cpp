#include<stdio.h>
int H[100]={0};  //全局变量，方便函数内调用 
int m, p, i, j;  //全局变量，方便函数内调用 

int IsInHashTable(int n)
{
	int flag = 0;
	for(i=0;i<m;i++)
	{
		if(H[i] == n)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

void Insert(int n)
{
	int loc,temp;
	loc = n % p;
	if(H[loc] == 0)           //若位置loc未被占用 
	{
	 
		H[loc] = n;
		printf("%d\n",loc);   //打印当前插入位置 
	}
	else                      //若位置loc被占用，采用线性探测再散列解决冲突 
	{
		for(i=1;i<m;i++)
		{
			temp = (loc + i) % m;     //注意，这里mod是表长 
			if(H[temp] == 0)          //找到了空位置 
			{
				H[temp] = n;
				printf("%d\n",temp);  //打印当前插入位置 
				break;                //结束循环 
			}
		}
	}
}

int NumOfElem()  //统计哈希表中元素个数 
{
	int num = 0;
	for(i=0;i<m;i++)
	{
		if(H[i] != 0)
			num++;
	}
	return num;
}

int LocateNum(int n)  //返回n在哈希表中的位置 
{
	int loc;
	for(i=0;i<m;i++)
	{
		if(H[i] == n)
		{
			loc = i;
			break;
		}	
	}
	return loc;
}

int main()
{
	int n;
	scanf("%d %d",&m,&p);
	while(scanf("%d",&n) && n != -1)  //当n不为-1时循环输入，每输入一个n进行一轮相关操作 
	{
		if(IsInHashTable(n))          //若n在哈希表中 
			printf("%d\n",LocateNum(n));
		else                          //若n不在哈希表中 
		{
			if(NumOfElem() == m - 1)  //若当前哈希表中关键字的个数等于m-1 
			{
				printf("Table full");
				return 0;             //程序结束 
			}
			else                      //若当前哈希表中关键字的个数不等于m-1 
			{
				Insert(n);            //将关键字插入哈希表,并输出该关键字插入在哈希表中的位置 
			}
		}
	}
	return 0;
}

