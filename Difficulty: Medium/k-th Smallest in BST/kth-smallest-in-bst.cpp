/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void f(Node* root,int k,int& ans,int& c){
        if(!root)return;
        f(root->left,k,ans,c);
        c++;
        if(c==k)ans=root->data;
        f(root->right,k,ans,c);
        
        
    }
    int kthSmallest(Node *root, int k) {
        // code here
        int ans=-1;
        int c=0;
        f(root,k,ans,c);
        return ans;
    }
};