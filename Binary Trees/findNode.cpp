#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

// SOLUTION
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if(root==NULL)
        return false;

    if(root->data == x)
        return true;

    bool smallLeft = isNodePresent(root->left, x);
    bool smallRight = isNodePresent(root->right, x);

    return smallLeft||smallRight;
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
    int x;
    cin >> x;
    cout << ((isNodePresent(root, x)) ? "true" : "false");
}