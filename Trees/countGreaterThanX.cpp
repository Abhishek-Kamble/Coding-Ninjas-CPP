//Program to count number of nodes greater than x
#include<iostream>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInput()
{
    int rootData;
    cout << "Enter Data: " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    int n;
    cout << "Enter Number of children of " << rootData << endl;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

int getLargeNodeCount(TreeNode<int>* root, int x) {
    int ans = 0;
    if(root->data > x)
        ans++;
    for(int i=0; i < root->children.size(); i++)
    {
        ans += getLargeNodeCount(root->children[i], x);
    }
    
    return ans;
}

int main()
{
    TreeNode<int>* root = takeInput();
    int x;
    cout << "Enter x: ";
    cin >> x;
    cout << "Ans: " << getLargeNodeCount(root, x);
    return 0;
}