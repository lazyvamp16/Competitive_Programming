class node{
public:
    int key,val;
    node *next, *prev;
    node(int k, int v){
        key = k;
        val = v;
    }
};

class LRUCache {
node* head = new node(-1,-1);
node* tail = new node(-1,-1);
int cap;
unordered_map<int,node*> m;

public:
    LRUCache(int c) {
        cap = c;
        head->next = tail;
        tail->prev = head;
    }
    
    void add(node* n){
        node* temp = head->next;
        head->next = n;
        n->prev = head;
        n->next = temp;
        temp->prev = n;
    }

    void del(node* n){
        node* nextemp = n->next;
        node* prevtemp = n->prev;
        prevtemp->next = nextemp;
        nextemp->prev = prevtemp;
    }

    int get(int key) {
        if(m.count(key)){
            int ans = m[key]->val;
            del(m[key]);
            add(m[key]);
            m.erase(key);
            m[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            del(m[key]);
            m.erase(key);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            del(tail->prev);
        }
        node* n = new node(key,value);
        add(n);
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */