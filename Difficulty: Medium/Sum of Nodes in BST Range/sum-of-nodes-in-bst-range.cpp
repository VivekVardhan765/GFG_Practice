/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        if(!root)return 0;
        int ans=0;
        ans+=nodeSum(root->left,l,r);
        ans+=nodeSum(root->right,l,r);
        if(root->data<=r and root->data>=l)ans+=root->data;
        return  ans;
        
        
    }
};
