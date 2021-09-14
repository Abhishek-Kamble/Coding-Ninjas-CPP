#include <iostream>
#include <queue>
#include <vector>
#include <climits>
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

//SOLUTION
class Pair{
    public:
TreeNode<int>* max=NULL;
    TreeNode<int>* smax=NULL;
};
Pair helper(TreeNode<int> *root)
{
     if(root==NULL)
    {
        Pair ans;
        ans.max=NULL;
        ans.smax=NULL;
        return ans;
    }
    Pair ans;
    ans.max=root;
    ans.smax=NULL;
    for(int i=0;i<root->children.size();i++)
    {
        Pair temp=helper(root->children[i]);
        if(ans.smax==NULL && temp.smax==NULL)
        {
            if(temp.max->data>ans.max->data)
            {  TreeNode<int>* a=ans.max;
                ans.max=temp.max;
                ans.smax=a;
            }
            else  if(temp.max->data<ans.max->data)
            {
                ans.smax=temp.max;
            }
        }
    else    if(ans.smax==NULL && temp.smax!=NULL)
        {
            if(temp.max->data>ans.max->data)
            {
                int a=max(ans.max->data,temp.smax->data);
                TreeNode<int>* s=new TreeNode<int>(a);
                ans.max=temp.max;
                ans.smax=s;
            }
            else if (temp.max->data<ans.max->data)
            {
                ans.smax=temp.max;
            }
        }
      else   if(ans.smax!=NULL && temp.smax==NULL)
         {
             if(temp.max->data>ans.max->data)
             {
                 ans.smax=ans.max;
                 ans.max=temp.max;
             }
             else if (temp.max->data<ans.max->data)
             {
                                 int a=max(ans.smax->data,temp.max->data);
                TreeNode<int>* s=new TreeNode<int>(a);
                 ans.smax=s;
             }
         }
    else    if(ans.smax!=NULL && temp.smax!=NULL)
        {
            if(temp.max->data>ans.max->data)
            {     int a=max(ans.max->data,temp.smax->data);
                TreeNode<int>* s=new TreeNode<int>(a);
                ans.smax=s;
                ans.max=temp.max;
            }
            else if(temp.max->data<ans.max->data)
            {
                 int a=max(ans.smax->data,temp.smax->data);
                TreeNode<int>* s=new TreeNode<int>(a);
                ans.smax=s;
            }
        }
        
            
    }
    return ans;

}

TreeNode <int>*  getSecondLargestNode(TreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
   return helper(root).smax;
}

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

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}