#include<stdio.h>
#include<string.h>
using namespace std;
struct node
{
	node *lchild;
	node *rchild;
	int c;
}tree[100];
int loc = 0;
char str1[30], str2[30];
int size1, size2;
char *str;
int *daxiao;
node *creat()
{
	tree[loc].lchild = tree[loc].rchild = NULL;
	return &tree[loc++];
}
void preorder(node *t)
{
	str[(*daxiao)++] = t->c + '0';
	if (t->lchild != NULL)
		preorder(t->lchild);
	if (t->rchild != NULL)
		preorder(t->rchild);
}
void inorder(node *t)
{
	if (t->lchild != NULL)
		inorder(t->lchild);
	str[(*daxiao)++] = t->c + '0';
	if (t->rchild != NULL)
		inorder(t->rchild);
}
node *Insert(node *t,int x)
{
	if (t == NULL)
	{
		t = creat();
		t->c = x;
		return t;
	}
	else if (x < t->c)
		t->lchild = Insert(t->lchild, x);
	else if (x > t->c)
		t->rchild = Insert(t->rchild, x);
	return t;
}
int main()
{
	int n,i,k=0,a[1000];
	while (scanf("%d", &n) != EOF && n != 0)
	{
		node *t=NULL;
		char temp[30];
		scanf("%s", temp);
		for (int i = 0; temp[i] != 0; i++)
			t= Insert(t, temp[i] - '0');
		int size1 = 0;
		str = str1;
		daxiao = &size1;
		preorder(t);
		inorder(t);
		str1[size1] = 0;
		for (int i = 0; i < n; i++)
		{
			node *T=NULL;
			scanf("%s", temp);
			for (int i = 0; temp[i] != 0; i++)
				T= Insert(T, temp[i] - '0');
			int size2 = 0;
			daxiao = &size2;
			str = str2;
			preorder(T);
			inorder(T);
			str2[size2] = 0;
			int jud = strcmp(str1, str2);
			if (jud != 0)
				a[k] = 0;
			else
				a[k] = 1;
			k++;
		}
	}
	for(i=0;i<k;i++)
	{
		if(a[i]==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

