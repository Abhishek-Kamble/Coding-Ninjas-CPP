//Program to take tree input and print tree levelwise
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

void printTreeLevelwise(TreeNode<int>* root)
{
    if(root==NULL)
        return;
    
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        TreeNode<int>* frontNode = pendingNodes.front();
        pendingNodes.pop();
        cout << frontNode->data << ": ";
        for(int i=0; i<frontNode->children.size(); i++)
        {
            if(i == frontNode->children.size()-1)
                cout << frontNode->children[i]->data;
            else
                cout << frontNode->children[i]->data << ", ";
            pendingNodes.push(frontNode->children[i]);
        }
        cout << endl;
    }

}

int main()
{
    TreeNode<int>* root = takeInput();
    printTreeLevelwise(root);
    return 0;
}