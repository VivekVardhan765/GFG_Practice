/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    unordered_map<Node*,int>mpp;
    int getMaxSum(Node *root) {
        if(!root)return 0;
        if(mpp.count(root))return mpp[root];
        int l=getMaxSum(root->left);
        int r=getMaxSum(root->right);
        int l1=0,r1=0;
        if(root->left)l1=getMaxSum(root->left->left)+getMaxSum(root->left->right);
        if(root->right)r1=getMaxSum(root->right->left)+getMaxSum(root->right->right);
        return mpp[root]=max(root->data+l1+r1, l+r);
    }
};