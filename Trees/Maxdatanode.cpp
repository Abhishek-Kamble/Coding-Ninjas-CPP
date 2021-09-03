//Max data node
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

TreeNode<int>* maxDataNode(TreeNode<int>* root)
{
    TreeNode<int>* maxDNode = root;

    for(int i=0; i<root->children.size(); i++)
    {
        TreeNode<int>* temp = maxDataNode(root->children[i]);
        if(temp->data > root->data)
            maxDNode = temp;
    }
    
    return maxDNode;
}
int main()
{
    TreeNode<int>* root = takeInput();
    cout << "\nAns: " << maxDataNode(root)->data;
    return 0;
}