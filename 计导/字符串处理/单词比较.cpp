#include<bits/stdc++.h>
using namespace std;


int main()
{   int n,i;
    string str[100];
    scanf("%d",&n);
    for (i=0;i<n;i++)
    cin>>str[i];
    sort(str,str+n);
    for (i=0;i<n;i++)
    cout<<str[i]<<endl;
    return 0;
}
