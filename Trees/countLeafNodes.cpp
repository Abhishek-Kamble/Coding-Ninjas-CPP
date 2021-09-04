//Count leaf nodes
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int getLeafNodeCount(TreeNode<int>* root) {
    if(root==NULL)
        return 0;
    if(root->children.size() == 0)
        return 1;

    int cnt = 0;
    for(int i=0; i<root->children.size(); i++)
    {
        cnt += getLeafNodeCount(root->children[i]);
    }
    return cnt;   
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << "Ans: " <<  getLeafNodeCount(root);
}