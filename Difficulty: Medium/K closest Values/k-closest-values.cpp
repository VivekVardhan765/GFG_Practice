/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void f(Node* root,int target,int k,deque<int>& dq){
        if(!root)return;
        f(root->left,target,k,dq);
        if(dq.empty())dq.push_front(root->data);
        else if(dq.size()==k){
            int maxdiff=abs(dq.front()-target);
            int currdiff=abs(root->data-target);
            if(maxdiff>currdiff){
                dq.pop_front();
                dq.push_back(root->data);
            }
            else return;
        }
        else dq.push_back(root->data);
        f(root->right,target,k,dq);
        
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        deque<int>dq;
        f(root,target,k,dq);
        vector<int>ans(dq.begin(),dq.end());
        return ans;
    }
};