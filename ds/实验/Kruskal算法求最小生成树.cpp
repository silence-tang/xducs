#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std; 
int m,n,root_node[100];     //定义顶点个数、边的个数，数组root_node储存根结点  

struct Edge                 //定义边的结构体 
{
    int a;
	int b;                  //一条边的两个顶点u、v 
	int weight;             //边的权值weight 
}edge[100];

bool judge(Edge a,Edge b)   //定义函数，实现边按权值的升序排列 
{
    return a.weight <= b.weight;
}

void init()
{
	int i;
    for(i = 1; i <= n; i++) 
        root_node[i] = -1;
    
}

int search(int node)        //查找并返回节某个节点所属集合的根结点 
{
    int temp,root;
    for(root = node; root_node[root] >= 0; root=root_node[root]);
    while(root != node)
    {
    	temp = root_node[node];
        root_node[node] = root;
        node = temp;        //两两交换 
    }
    return root;   
}
 
void hebing(int node1,int node2)
{
	
    int root1 = search(node1), root2 = search(node2);   //r1是R1的根结点 
    int temp = root_node[root1] + root_node[root2];
    if(root_node[root1] > root_node[root2])             //加权法则 
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
    //int sum_weight = 0;             //生成树的总权值 
    int N = 0;                        //已被选中作为最小生成树的边的数目
    int a, b, i, max, min;            //边的两顶点
    init();                           //对root_node数组进行初始化
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
			}                         //让输出的边的两顶点按从小到大的顺序输出 
            printf("%d %d %d\n",min,max,edge[i].weight);
            //sum_weight += edge[i].weight;
			N++;
            hebing(a,b);
        }
        if(N >= n - 1)
			break;
    }
    //printf("最小生成树的总权值为：%d\n",sum_w);
}

int main( )
{
	
    int i, a, b, weight;                 //定义边的起点和终点及权值
    scanf("%d %d",&n,&m);                //输入顶点个数和边数
    for(i = 0; i < m; i++)
    {
    	scanf("%d %d %d",&a,&b,&weight); //输入边的起点、终点和权值 
    	edge[i].a = a;
		edge[i].b = b;
		edge[i].weight = weight;
    }
    sort(edge,edge+m,judge);             //先将边按权值升序排列，便于后续的结果输出 
    Kruskal_MST();                       //调用函数，求最小生成树 
    return 0;
}
