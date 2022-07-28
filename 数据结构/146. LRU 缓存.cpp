struct LinkedNode{
    LinkedNode* pre;
    LinkedNode* next;
    int val, key;
    LinkedNode(): key(0), val(0), pre(NULL), next(NULL){}
    LinkedNode(int _key, int _val): key(_key), val(_val), pre(NULL), next(NULL){}
};

class LRUCache {
private:
    int capacity;
    int size;
    unordered_map<int, LinkedNode*> hash;
    LinkedNode* head;
    LinkedNode* tail;

public:

    LRUCache(int _capacity) {
        capacity = _capacity;
        size = 0;
        head = new LinkedNode();
        tail = new LinkedNode();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(!hash.count(key)) return -1;
        moveToHead(hash[key]);
        return hash[key]->val;
    }
    
    void put(int key, int value) {
        if(!hash.count(key)){
            size ++;
            auto node = new LinkedNode(key, value);
            hash[key] = node;
            addToHead(node);
            if(size > capacity){
                auto node = removeTail();
                hash.erase(node->key);
                delete node;
                size --;
            }
        } else {
            auto node = hash[key];
            node->val = value;
            moveToHead(node);
        }
    }


    void moveToHead(LinkedNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
    }

    void addToHead(LinkedNode* node){
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
    }

    LinkedNode* removeTail(){
        auto node = tail->pre;
        node->pre->next = tail;
        tail->pre = node->pre;
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */