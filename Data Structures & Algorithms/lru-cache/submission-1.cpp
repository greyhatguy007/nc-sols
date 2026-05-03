class LRUCache {
   public:
    struct node {
        int val;
        int key;
        node* prev;
        node* next;
        node(int v, int k, node* n = nullptr, node* p = nullptr)
            : val(v), key(k), next(n), prev(p) {}
    };

    int space;
    node* head;
    node* tail;

    unordered_map<int, node*> mp;

    LRUCache(int capacity) {
        space = capacity;
        tail = new node(0, 0);
        head = new node(0, 0, tail);
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        node* current = mp[key];
        current->prev->next = current->next;
        current->next->prev = current->prev;
        current->prev = tail->prev;
        current->next = tail;
        tail->prev->next = current;
        tail->prev = current;
        return current->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            node* current = mp[key];
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current->prev = tail->prev;
            current->next = tail;
            tail->prev->next = current;
            tail->prev = current;
            current->val = value;
        } else {
            if (space == 0) {
                node* redundant = head->next;
                head->next = redundant->next;
                redundant->next->prev = head;
                mp.erase(redundant->key);
                free(redundant);
                space++;
            }
            node* current = new node(value, key);
            mp[key] = current;
            current->prev = tail->prev;
            tail->prev->next = current;
            tail->prev = current;
            current->next = tail;
            space--;
        }
    }
};
