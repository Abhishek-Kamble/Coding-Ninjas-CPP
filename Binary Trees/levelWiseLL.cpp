#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

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

vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> ans;
    if (root == NULL)
        return ans;

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *current = pendingNodes.front();
        pendingNodes.pop();
        if (current != NULL)
        {
            Node<int> *newNode = new Node<int>(current->data);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            if (current->left != NULL)
            {
                pendingNodes.push(current->left);
            }
            if (current->right != NULL)
            {
                pendingNodes.push(current->right);
            }
        }
        else if (current == NULL)
        {
            if (pendingNodes.empty())
            {
                tail->next = NULL;
                ans.push_back(head);
                break;
            }
            pendingNodes.push(NULL);
            tail->next = NULL;
            ans.push_back(head);
            head = NULL;
            tail = NULL;
        }
    }

    return ans;
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;

    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++)
    {
        print(ans[i]);
    }
}