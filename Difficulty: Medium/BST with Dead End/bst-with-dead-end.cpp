/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool f(int lb,int rb,Node* root){
        if(!root)return false;
        if(root->data==lb and root->data==rb)return true;
        return (f(root->data + 1,rb,root->right) or f(lb,root->data -1,root->left));
    }
    bool isDeadEnd(Node *root) {
        return (f(root->data + 1,INT_MAX,root->right) or f(1,root->data -1,root->left));
    }
};