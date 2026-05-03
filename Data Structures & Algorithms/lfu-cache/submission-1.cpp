class LFUCache {
   public:
    struct node {
        int key;
        int value;
        int freq;
        node* next;
        node* prev;
        node(int k, int v, node* p = nullptr, node* n = nullptr)
            : key(k), value(v), next(n), prev(p), freq(1) {}
    };

    int count;
    map<int, pair<node*, node*>> fm;  // frequency map of <head,tail>
    map<int, node*> mp;

    LFUCache(int capacity) { count = capacity; }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        // get the node, update the freq, insert in corresponding freqmap
        node* current = mp[key];
        int freq = current->freq;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        // check if head next is tail, if yes erase key from fm
        node* oldhead = fm[freq].first;
        node* oldtail = fm[freq].second;
        if (oldhead->next == oldtail) fm.erase(freq);
        freq++;
        current->freq = freq;
        if (fm.find(freq) == fm.end()) {
            node* tail = new node(0, 0);
            node* head = new node(0, 0);
            head->next = current;
            current->prev = head;
            tail->prev = current;
            current->next = tail;
            fm[freq] = {head, tail};
        } else {
            node* head = fm[freq].first;
            node* tail = fm[freq].second;
            current->prev = tail->prev;
            tail->prev->next = current;
            current->next = tail;
            tail->prev = current;
        }
        return current->value;
    }

    void put(int key, int value) {
        if (count == 0) {  // full, remove entry
            int freq = fm.begin()->first;
            node* head = fm[freq].first;
            node* tail = fm[freq].second;
            node* depreciated = head->next;
            depreciated->prev->next = depreciated->next;
            depreciated->next->prev = depreciated->prev;
            mp.erase(depreciated->key);
            delete (depreciated);
            if (head->next == tail) fm.erase(freq);
            count++;
        }
        if (mp.find(key) != mp.end()) {  // entry already exists
            node* current = mp[key];
            current->value = value;
            int freq = current->freq;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            node* oldhead = fm[freq].first;
            node* oldtail = fm[freq].second;
            if (oldhead->next == oldtail) fm.erase(freq);
            freq++;
            current->freq = freq;
            if (fm.find(freq) != fm.end()) { // freq already exists
                node* head = fm[freq].first;
                node* tail = fm[freq].second;
                current->prev = tail->prev;
                tail->prev->next = current;
                current->next = tail;
                tail->prev = current;
            } else {
                node* tail = new node(0, 0);
                node* head = new node(0, 0);
                head->next = current;
                current->prev = head;
                tail->prev = current;
                current->next = tail;
                fm[freq] = {head, tail};
            }
        } else {  // new key
            node* current = new node(key, value);
            mp[key] = current;
            int freq = current->freq;
            if (fm.find(freq) == fm.end()) {  // no freq key in freq map
                node* tail = new node(0, 0);
                node* head = new node(0, 0);
                head->next = current;
                current->prev = head;
                tail->prev = current;
                current->next = tail;
                fm[freq] = {head, tail};
            } else {  // freq key exists in freq map
                node* head = fm[freq].first;
                node* tail = fm[freq].second;
                current->prev = tail->prev;
                tail->prev->next = current;
                current->next = tail;
                tail->prev = current;
            }
            count--;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */