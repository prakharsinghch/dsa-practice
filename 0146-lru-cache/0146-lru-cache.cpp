class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val): key(key), val(val), prev(nullptr), next(nullptr) {};
};

class LRUCache {
public:
    int c;
    unordered_map<int,Node*> mp;
    Node* latest;
    Node* oldest;
    LRUCache(int capacity) {
        c = capacity;
        latest = new Node(0,0);
        oldest = new Node(0,0);
        latest->prev = oldest;
        oldest->next = latest;
    } 
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* x= mp[key];
            remove(x);
            insert(x);
            return x->val;
        }

        return -1;
    }

    void remove(Node* n){
        Node* prev = n->prev;
        Node* nxt = n->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(Node* n){
        Node* prev = latest->prev;
        Node* nxt = latest;
        prev->next = n;
        nxt->prev = n;
        n->prev = prev;
        n->next = nxt;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            remove(mp[key]);
        }
        Node* n = new Node(key,value);
        mp[key] = n;
        insert(n);

        if(mp.size() > c){
            Node* o = oldest->next;
            remove(o);
            mp.erase(o->key);
            delete o;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */