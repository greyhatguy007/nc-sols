class MyHashSet {
public:
    static const int mod = 32;
    int arr[1000000/mod + 1] = {0};
    MyHashSet() {
        
    }
    
    void add(int key) {
        int maj = key/mod;
        int min = key%mod;
        int curr = arr[maj];
        curr = (1<<min) | curr; 
        arr[maj] = curr;
    }
    
    void remove(int key) {
        int maj = key/mod;
        int min = key%mod;
        int curr = arr[maj];
        curr = ~(1<<min) & curr; 
        arr[maj] = curr;
    }
    
    bool contains(int key) {
        int maj = key/mod;
        int min = key%mod;
        int curr = arr[maj];
        int ans = (1<<min) & curr;
        return ans!=0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */