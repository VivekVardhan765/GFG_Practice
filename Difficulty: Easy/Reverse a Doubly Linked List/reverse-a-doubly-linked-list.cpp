/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        Node* temp=head;
        while(temp->next){
            Node* n=temp->next;
            temp->next=temp->prev;
            temp->prev=n;
            temp=n;
        }
        temp->next=temp->prev;
        temp->prev=NULL;
        return temp;
    }
};