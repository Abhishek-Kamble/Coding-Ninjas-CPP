#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

void printTree(BinaryTreeNode<int> *root)
{
    //base case
    if (root == NULL)
        return;

    cout << root->data << ": ";
    if (root->left != NULL)
        cout << " L: " << root->left->data;

    if (root->right != NULL)
        cout << " R: " << root->right->data;

    cout << endl;

    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter Left child of " << front->data << ": " << endl;
        int childData;
        cin >> childData;
        if (childData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(childData);
            pendingNodes.push(leftChild);
            root->left = leftChild;
        }

        cout << "Enter Right child of " << front->data << ": " << endl;
        cin >> childData;
        if (childData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(childData);
            pendingNodes.push(rightChild);
            root->right = rightChild;
        }
    }

    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    delete root;
}