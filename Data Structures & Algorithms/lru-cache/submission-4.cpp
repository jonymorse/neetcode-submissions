class Node{
public:
    int key;
    int value;
    Node* prev; 
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};
class LRUCache{
    private:
    int cap;
    Node* head; //= new Node(0,0);
    Node* tail;
    unordered_map<int, Node*> cacheL;
    list<int> order; 
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    void insert(Node* node){
        Node* prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;
    }
    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    public:
    LRUCache(int capacity){
        cap = capacity ;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    int get(int key){
        auto it = cache.find(key);
        if(it != cache.end()){
            auto valueListPair = it->second;
            order.erase(valueListPair.second);
            order.push_back(key);
            valueListPair.second = --order.end();
            return valueListPair.first;
        }
        return -1;
    }
    void put(int key, int value){
        auto it = cache.find(key);
        if(it != cache.end()){
            auto valueListPair = it->second;
            order.erase(valueListPair.second);
        }
        order.push_back(key);
        cache[key] = {value, --order.end()};

        if(cache.size() > cap){
            int keyToBeRemoved = order.front();
            order.pop_front();
            cache.erase(keyToBeRemoved);
        }
    }

};