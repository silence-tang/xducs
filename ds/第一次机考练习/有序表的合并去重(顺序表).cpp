#include<iostream>
#define InitSize 100000
using namespace std;

typedef int ElemType;
typedef struct
{
	ElemType *data;
	int length, MaxSize;
}SeqList;

void InitList(SeqList &L)
{
	L.data = new ElemType[InitSize];
	if (!L.data){ cout << "存储空间申请失败！"; return; }
	L.length = 0;
	L.MaxSize = InitSize;
}

bool Merge(SeqList A, SeqList B, SeqList &C)
{
	if (A.length + B.length > C.MaxSize) return false;//超出最大存储空间 
	int i = 0, j = 0, k = 0;
	while( i < A.length && j < B.length)
	{
		if (A.data[i] <= B.data[j])
			C.data[k++] = A.data[i++];
		else
			C.data[k++] = B.data[j++];
	}
	while (i < A.length) C.data[k++] = A.data[i++];
	while (j < B.length) C.data[k++] = B.data[j++];
	C.length = k;
	return true;
}

void printList(SeqList L)
{
	for (int i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}

int main()
{
	//定义并生成两个顺序表 
	SeqList A; InitList(A);
	SeqList B; InitList(B);
	int m,n,i,j;
	scanf("%d %d",&m,&n);
	A.length = m; B.length = n;
	for(i=0;i<=A.length-1;i++)
		scanf("%d",&A.data[i]);
	for(i=0;i<=B.length-1;i++)
		scanf("%d",&B.data[i]);
	SeqList C;
	InitList(C);
	if (Merge(A,B,C))
	{
		for(i=0;i<=m+n-1;i++)
		{
			for(j=i+1;j<=m+n-1;j++)
			{
				if(C.data[j] == C.data[i])
					C.data[j] = 0;
			}
		}
		for(i=0;i<=m+n-1;i++)
		{
			if(C.data[i] != 0)
				printf("%d ",C.data[i]);
		}
	}
	 return 0;
}

