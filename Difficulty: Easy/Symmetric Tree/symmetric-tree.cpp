/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool f(Node* r,Node* l){
        if(!r and !l)return true;
        if(!r or !l)return false;
        if(r->data!=l->data)return false;
        else{
            return (f(r->right,l->left) and f(l->right,r->left) );
        }
    }
    bool isSymmetric(Node* root) {
        return f(root->right,root->left);
    }
};