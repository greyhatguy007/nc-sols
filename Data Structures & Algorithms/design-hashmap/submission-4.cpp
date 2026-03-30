class MyHashMap {
public:

    struct node {
        int key;
        int value;
        bool deleted;
        bool occupied;

        node(){
            deleted = false;
            occupied = false;
        }
    };

    static const int SIZE = 10000;

    node map[SIZE];

    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int index = key%SIZE;
        int start = index;
        int firstTombstone = -1;
        while(true){
            if (map[index].occupied && map[index].key == key) {
                map[index].value = value;
                return;
            } else if(!map[index].occupied && !map[index].deleted){
                map[index].key = key;
                map[index].value = value;
                map[index].occupied = true;
                map[index].deleted = false;
                return;
            } else if(!map[index].occupied && map[index].deleted && firstTombstone == -1) { // tombstone
                firstTombstone = index;
            }     
            index = (index+1)%SIZE;

            if(index==start) {
                if(firstTombstone == -1) return;
                map[firstTombstone].key = key;
                map[firstTombstone].value = value;
                map[firstTombstone].occupied = true;
                map[firstTombstone].deleted = false;
                return;
            }   
        }
    }
    
    int get(int key) {
        int index = key%SIZE;
        int start = index;
        while(true){
            if(!map[index].occupied && !map[index].deleted){
                return -1;
            } else if(map[index].occupied && map[index].key==key){
                return map[index].value;
            } else {
                index = (index+1)%SIZE;
                if(start==index) return -1;
            }
        }
    }
    
    
    void remove(int key) {
        int index = key%SIZE;
        int start = index;
        while(true){
            if(!map[index].occupied && !map[index].deleted) {
                return;
            } else if (map[index].occupied && map[index].key==key){
                map[index].occupied = false;
                map[index].deleted = true;
                return;
            } else {
                index = (index+1)%SIZE;
                if(index==start) return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */