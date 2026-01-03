/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        if(head1==head2)return head1;
        Node* temp=head1;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head1;
        Node* fast=head2;
        Node* slow=head2;
        do{
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);
        slow=head2;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        temp->next=NULL;
        return slow;
    }
};