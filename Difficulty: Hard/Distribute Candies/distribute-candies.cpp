/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int f(Node* root, int& ans){
        if(!root)return 0;
        int l=f(root->left,ans);
        int r=f(root->right,ans);
        ans+= abs(l)+abs(r)+root->data-1;
        return root->data-1+l+r;
    }
    int distCandy(Node* root) {
        int ans=0;
        f(root,ans);
        return ans;
        
    }
};