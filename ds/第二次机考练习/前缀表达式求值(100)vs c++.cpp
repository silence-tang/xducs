#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<deque>
#include<sstream>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	stack<int>st;
	stringstream sm(str);
	vector<string>vec;
	string temp;
	sm >> temp;
	while (sm)
	{
		vec.push_back(temp);
		sm >> temp;
	}
	int index = vec.size() - 1;
	while (index >= 0)
	{
		switch (vec[index][0])
		{
		case'+':
		{
			int arg1 = st.top();
			st.pop();
			int arg2 = st.top();
			st.pop();
			st.push(arg1 + arg2);
			break;
		}
		case'-':
		{
			int arg1 = st.top();
			st.pop();
			int arg2 = st.top();
			st.pop();
			st.push(arg1 - arg2);
			break;
		}
		case'*':
		{
			int arg1 = st.top();
			st.pop();
			int arg2 = st.top();
			st.pop();
			st.push(arg1 * arg2);
			break;
		}
		case'/':
		{
			int arg1 = st.top();
			st.pop();
			int arg2 = st.top();
			st.pop();
			st.push(arg1 / arg2);
			break;
		}
		default:
		{
			sm = stringstream(vec[index]);
			int temp;
			sm >> temp;
			st.push(temp);
			break;
		}
		}
		index--;
	}
	cout << st.top();
	return 0;
}
