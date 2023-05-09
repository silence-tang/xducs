#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
 
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
 
bool isBiTree(int &pre, TreeNode *root)
{
    if(root==NULL)
        return true;
    if(!isBiTree(pre, root->left))
        return false;
    if(pre>=root->val)
        return false;
    else
        pre = root->val;
    if(!isBiTree(pre, root->right))
        return false;
    return true;
}
 
int main(){
    int n,t,v,l,r;
    cin>>n>>t;
    TreeNode *T = (TreeNode*)malloc(sizeof(TreeNode)*(n+1));
    TreeNode *R = &T[t];
    for(int i=1;i<=n;i++)
	{
        cin>>v>>l>>r;
        T[i].val = v;                       
        T[i].left = l?&T[l]:0;
        T[i].right = r?&T[r]:0;
    }
    int pre = -1;
    cout<<(isBiTree(pre,R)?"true":"false")<<endl;
    return 0;
}
