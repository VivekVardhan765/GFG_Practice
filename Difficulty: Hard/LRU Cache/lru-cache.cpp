//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  public:
    class Node {
    public:
        int key;
        Node* next;
        Node* prev;
        Node(int k) : key(k), next(nullptr), prev(nullptr) {}
    };
    
    private:
        int capacity, size;
        Node* head;
        Node* tail;
        unordered_map<int, pair<int, Node*>> cache;
    
        void addNode(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
        }
    
        void removeNode(Node* node) {
            Node* prevNode = node->prev;
            Node* nextNode = node->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
    
        void moveToFront(Node* node) {
            removeNode(node);
            addNode(node);
        }
    
    public:
        LRUCache(int cap) {
            capacity = cap;
            size = 0;
            head = new Node(-1);
            tail = new Node(-1);
            head->next = tail;
            tail->prev = head;
        }
    
        int get(int key) {
            if (cache.find(key) == cache.end()) {
                return -1;
            }
            Node* node = cache[key].second;
            moveToFront(node);
            return cache[key].first;
        }
    
        void put(int key, int value) {
            if (cache.find(key) != cache.end()) {
                cache[key].first = value;
                Node* node = cache[key].second;
                moveToFront(node);
            } else {
                if (size == capacity) {
                    Node* lru = tail->prev;
                    removeNode(lru);
                    cache.erase(lru->key);
                    delete lru;
                    size--;
                }
                Node* newNode = new Node(key);
                addNode(newNode);
                cache[key] = {value, newNode};
                size++;
            }
        }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends