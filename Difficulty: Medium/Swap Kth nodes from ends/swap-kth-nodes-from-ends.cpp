/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        Node* r=head;
        k--;
        while( r and k--){
            r=r->next;
            
        }
        if(!r)return head;
        Node* temp=r;
        Node* l=head;
        while(r->next!=NULL){
            r=r->next;
            l=l->next;
        }
        swap(temp->data,l->data);
        return head;
    }
};