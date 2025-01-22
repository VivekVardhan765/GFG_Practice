//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
     Node* f(struct Node* head) {
        Node* c=head;
        Node* p=NULL;
        Node* n=head->next;
        while(n){
            c->next=p;
            p=c;
            c=n;
            n=n->next;
        }
        c->next=p;
        return c;
        
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        while(num1->data==0)num1=num1->next;
        while(num2->data==0)num2=num2->next;
        num1=f(num1);
        num2=f(num2);
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        int c=0;
        while(num1 and num2){
            int s=num1->data+num2->data+c;
            c=s/10;
            s=s%10;
            temp->next=new Node(s);
            temp=temp->next;
            num1=num1->next;
            num2=num2->next;
        }
        while(num1){
            int s=num1->data+c;
            c=s/10;
            s=s%10;
            temp->next=new Node(s);
            temp=temp->next;
            num1=num1->next;
        }
        while(num2){
            int s=num2->data+c;
            c=s/10;
            s=s%10;
            temp->next=new Node(s);
            temp=temp->next;
            num2=num2->next;
        }
        if(c==1){
            temp->next=new Node(1);
        }
        Node* head=dummy->next;
        dummy->next=NULL;
        return f(head);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends