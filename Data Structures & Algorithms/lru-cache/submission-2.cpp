class Node{
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private: 
    Node* left; 
    Node* right; 
    int cap; 
    unordered_map<int, Node*> cache;

    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next; 
        next->prev = prev; 
    }
    void insert(Node* node){
        Node* prev = right->prev; 
        prev->next = node;
        node->prev = prev; 
        node->next = right; 
        right->prev = node;
    }
public:
    LRUCache(int capacity) {
        left = new Node(0,0);
        right = new Node(0,0);
        cap = capacity;
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }
        Node* node = new Node{key,value};
        insert(node);
        cache[key] = node;
        if(cache.size() > cap){
            Node* lru = left->next;
            cache.erase(lru->key);
            remove(lru);
            delete(lru);
        }
    }
};
