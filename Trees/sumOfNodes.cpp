//Program to find sum of nodes of a tree
#include<iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInput()
{
    int rootData;
    cout << "Enter Root Data: " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        TreeNode<int>* frontNode = pendingNodes.front();
        pendingNodes.pop();
        int n;
        cout << "Enter number of children of " << frontNode->data << ": ";
        cin >> n;
        for(int i=0; i<n; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << frontNode->data << ": ";
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            frontNode->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int sumOfNodes(TreeNode<int>* root)
{
    int sum = root->data;
    for(int i=0; i<root->children.size(); i++)
    {
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}

int main()
{
    TreeNode<int>* root = takeInput();
    cout << "\nAns: " << sumOfNodes(root);
    return 0;
}