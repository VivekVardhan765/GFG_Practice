/* Structure for Tree Node
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
    int f(Node* root){
        if(!root) return 0;

        int left = f(root->left);
        int right = f(root->right);

        int old = root->data;
        root->data = left + right;

        return old + root->data;
    }

    void toSumTree(Node *root) {
        f(root);
    }
};