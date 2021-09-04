//Program to find Node with maximum child sum
#include<iostream>
#include "TreeNode.h"
using namespace std;

int countChildSum(TreeNode<int>* root)
{
    int ans=root->data;

    for(int i=0; i<root->children.size(); i++)
    {
        ans += root->children[i]->data;
    }

    return ans;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) 
{
    if(root==NULL)
        return root;

    TreeNode<int>* maxNode = root;
    for(int i=0; i<root->children.size(); i++)
    {
        int orgSum = countChildSum(maxNode);  
        TreeNode<int>* temp = maxSumNode(root->children[i]); 
        int currSum = countChildSum(temp);
        if(currSum > orgSum)
            maxNode = temp;
    }

    return maxNode;
}

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

int main()
{
    TreeNode<int>* root = takeInput();
    cout << "Ans: " << maxSumNode(root);
    return 0;
}