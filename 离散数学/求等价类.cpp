#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
//方法2 利用链表，将每个等价类的子集放在同一个链表中，消除了方法1中的问题
 
struct Node
{
	int val;
	int loc; //在哪个链表中
	Node *next;
	Node(int x) :val(x), next(NULL), loc(-1) {}
};
 
class EquivalClass2{
private:
 
	vector<Node*> numberLink;
	vector<Node*> number;
 
public:
	EquivalClass2(int n, vector<int> A, vector<int> B)
	{
		for (int i = 0; i < n; i++)
		{
			Node* num = new Node(i);
			number.push_back(num);
		}
 
		for (int i = 0; i < A.size(); i++)
		{
			int a = A[i];
			int b = B[i];
 
			Node *tmpA = number[a];
			Node *tmpB = number[b];
 
			if (tmpA->loc == -1 && tmpB->loc == -1)
			{
				tmpA->next = tmpB;
				int index = numberLink.size();
				tmpA->loc = index;
				tmpB->loc = index;
				numberLink.push_back(tmpA);
				
			}
			else if (tmpA->loc == -1 && tmpB->loc != -1)
			{
				Node* node = numberLink[tmpB->loc];
				while (node->next != NULL)
				{
					node = node->next;
				}
				node->next = tmpA;
				tmpA->loc = tmpB->loc;
 
			}
			else if (tmpA->loc != -1 && tmpB->loc == -1)
			{
				Node* node = numberLink[tmpA->loc];
				while (node->next != NULL)
				{
					node = node->next;
				}
				node->next = tmpB;
				tmpB->loc = tmpA->loc;
			}
			
 
		}
 
		for (int i = 0; i < number.size(); i++)
		{
			if (number[i]->loc == -1)
			{
				number[i]->loc = numberLink.size();
				numberLink.push_back(number[i]);
 
			}
		}
 
	}
 
	void printAllVec()
	{
		for (int i = 0; i < numberLink.size(); i++)
		{
			Node* node = numberLink[i];
			while (node != NULL)
			{
				cout << node->val << " ";
				node = node->next;
			}
			cout << endl;
		}
 
	}
 
	
};
 
int main(void)
{
    int b[4]={1,5,3,6};
	vector<int> A(b,b+4);
	int c[4]={2,1,0,5};
	vector<int> B = (c,c+4);
 
	EquivalClass2 equalClass(7, A, B);
 
	equalClass.printAllVec();
 
 
}
