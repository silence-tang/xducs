#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std; 
int m,n,root_node[100];     //���嶥��������ߵĸ���������root_node��������  

struct Edge                 //����ߵĽṹ�� 
{
    int a;
	int b;                  //һ���ߵ���������u��v 
	int weight;             //�ߵ�Ȩֵweight 
}edge[100];

bool judge(Edge a,Edge b)   //���庯����ʵ�ֱ߰�Ȩֵ���������� 
{
    return a.weight <= b.weight;
}

void init()
{
	int i;
    for(i = 1; i <= n; i++) 
        root_node[i] = -1;
    
}

int search(int node)        //���Ҳ����ؽ�ĳ���ڵ��������ϵĸ���� 
{
    int temp,root;
    for(root = node; root_node[root] >= 0; root=root_node[root]);
    while(root != node)
    {
    	temp = root_node[node];
        root_node[node] = root;
        node = temp;        //�������� 
    }
    return root;   
}
 
void hebing(int node1,int node2)
{
	
    int root1 = search(node1), root2 = search(node2);   //r1��R1�ĸ���� 
    int temp = root_node[root1] + root_node[root2];
    if(root_node[root1] > root_node[root2])             //��Ȩ���� 
    {
        root_node[root1] = root2; 
        root_node[root2] = temp;
    }
    
    else
    {
        root_node[root2] = root1; 
        root_node[root1] = temp;
    }
    
}

void Kruskal_MST()
{
    //int sum_weight = 0;             //����������Ȩֵ 
    int N = 0;                        //�ѱ�ѡ����Ϊ��С�������ıߵ���Ŀ
    int a, b, i, max, min;            //�ߵ�������
    init();                           //��root_node������г�ʼ��
    for(i = 0; i < m; i++)
    {
        a = edge[i].a;
		b = edge[i].b;
        if(search(a) != search(b))
        {
        	if(a>=b)
        	{
        		max=a;
        		min=b;
			}
			else
			{
				max=b;
				min=a;
			}                         //������ıߵ������㰴��С�����˳����� 
            printf("%d %d %d\n",min,max,edge[i].weight);
            //sum_weight += edge[i].weight;
			N++;
            hebing(a,b);
        }
        if(N >= n - 1)
			break;
    }
    //printf("��С����������ȨֵΪ��%d\n",sum_w);
}

int main( )
{
	
    int i, a, b, weight;                 //����ߵ������յ㼰Ȩֵ
    scanf("%d %d",&n,&m);                //���붥������ͱ���
    for(i = 0; i < m; i++)
    {
    	scanf("%d %d %d",&a,&b,&weight); //����ߵ���㡢�յ��Ȩֵ 
    	edge[i].a = a;
		edge[i].b = b;
		edge[i].weight = weight;
    }
    sort(edge,edge+m,judge);             //�Ƚ��߰�Ȩֵ�������У����ں����Ľ����� 
    Kruskal_MST();                       //���ú���������С������ 
    return 0;
}
