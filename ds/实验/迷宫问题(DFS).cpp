#include<iostream>
#include<stack>
#include<stdio.h> 
using namespace std;

class Node
{
public:
	int height, width, dict;
	Node(int h, int w, int d) :height(h), width(w), dict(d) {}
	Node(const Node &k) :height(k.height), width(k.width), dict(k.dict) {}
};

int** map;
int height, width;
int start_h, start_w;
int end_h, end_w;
stack<Node*> st;

int dict[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

enum { EAST, SOUTH, WEST, NORTH };

void INITIALIZE()
{
	cin >> height >> width;
	cin >> start_h >> start_w;
	cin >> end_h >> end_w;
	map = new int* [height + 2];
	for (int i = 0; i < height + 2; i++)
	{
		map[i] = new int[width + 2];
	}
	for (int i = 0; i < height + 2; i++)
	{
		map[i][0] = 1;
		map[i][width + 1] = 1;
	}
	for (int i = 0; i < width; i++)
	{
		map[0][i] = 1;
		map[height + 1][i] = 1;
	}
	for (int i = 1; i < height + 1; i++)
	{
		for (int k = 1; k < width + 1; k++)
		{
			cin >> map[i][k];
		}
	}
}

int DFS(Node* k)
{
	map[k->height][k->width] = 1;
	if (k->height == end_h && k->width == end_w)
	{
		k->dict = EAST;
		return true;
	}
	for (int i = EAST; i <= NORTH; i++)
	{
		Node* temp = new Node(k->height + dict[i][0], k->width + dict[i][1], i);
		k->dict = i;
		if (map[temp->height][temp->width] == 0 && DFS(temp))
		{
			st.push(temp);
			return true;
		}
		else
		{
			delete temp;
		}
	}
	return false;
}
int main()
{
	INITIALIZE();
	Node* k = new Node(start_h, start_w, EAST);
	DFS(k);
	if (st.empty())
	{
		cout << "no";
	}
	else
	{
		st.push(k);
		while (!st.empty())
		{
			cout << '(' << st.top()->height << ',' << st.top()->width << ',' << st.top()->dict+1 << ')';
			st.pop();
			if (!st.empty())
			{
				cout << ',';
			}
		}
	}
}
