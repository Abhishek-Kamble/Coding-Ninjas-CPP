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
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int ans = 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    if (lheight > rheight)
        ans = lheight;
    else
        ans = rheight;

    return ans + 1;
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
    cout << height(root) << endl;
}