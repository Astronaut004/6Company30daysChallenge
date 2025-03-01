/*
Question Overview

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/

class LRUCache {
public:
    class Node {
        public:
        int key;
        int data;
        Node* next;
        Node* prev;
        Node(int k, int d) {
            this->key = k;
            this->data = d;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int cap;
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        this->cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void addToFront(Node* nNode) {
        nNode->next = head->next;
        nNode->prev = head;
        head->next->prev = nNode;
        head->next = nNode;
    }

    void removeNode(Node* dNode) {
        dNode->prev->next = dNode->next;
        dNode->next->prev =  dNode->prev;
        dNode->next = nullptr;
        dNode->prev = nullptr;
    }
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* p = mp[key];
            int value = p->data;
            removeNode(p);
            addToFront(p);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* eNode = mp[key];
            removeNode(eNode);
            mp.erase(key);
        }
        if(mp.size() == cap) {
            Node* dNode = tail->prev;
            removeNode(dNode);
            mp.erase(dNode->key);
        }
        Node* newNode = new Node(key, value);
        addToFront(newNode);
        mp[key] = newNode;
    }
};