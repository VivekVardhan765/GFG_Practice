/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int f(Node* root, int &ans){
        if(!root)return 0;
        int l=max(0,f(root->right,ans));
        int r=max(f(root->left,ans),0);
        ans=max(root->data+l+r,ans);
        return root->data+max(l,r);
        
    }
    int findMaxSum(Node *root) {
        // code here
        int ans=root->data;
        f(root,ans);
        return ans;
    }
};