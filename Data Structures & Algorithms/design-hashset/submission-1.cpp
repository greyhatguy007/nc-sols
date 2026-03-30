class MyHashSet {
public:
    int arr[125001] = {0};
    MyHashSet() {
        
    }
    
    void add(int key) {
        int maj = key/8;
        int min = key%8;
        int curr = arr[maj];
        curr = (1<<min) | curr; 
        arr[maj] = curr;
    }
    
    void remove(int key) {
        int maj = key/8;
        int min = key%8;
        int curr = arr[maj];
        curr = ~(1<<min) & curr; 
        arr[maj] = curr;
    }
    
    bool contains(int key) {
        int maj = key/8;
        int min = key%8;
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