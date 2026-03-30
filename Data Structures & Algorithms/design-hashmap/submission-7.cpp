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

    node* map;  
    int OCCUPIED;
    int SIZE;
    const float LF_THRESHOLD = 0.75;

    MyHashMap() {
        SIZE = 100;
        OCCUPIED = 0;
        map = new node[SIZE];
    }

    float getLF(){
        return (float)OCCUPIED / SIZE;
    }

    void reHash(){
        int newSize = SIZE * 2;
        node* newMap = new node[newSize];
        node* oldMap = map;
        int oldSize = SIZE;
        map = newMap;
        SIZE = newSize;
        OCCUPIED = 0;
        for(int i = 0; i < oldSize; i++){
            if(oldMap[i].occupied){
                put(oldMap[i].key, oldMap[i].value);
            }
        }
        delete[] oldMap;     
    }
    
    void put(int key, int value) {
        int index = key % SIZE;
        int start = index;
        int firstTombstone = -1;
        while(true){
            if (map[index].occupied && map[index].key == key) {
                map[index].value = value;
                return;
            } else if(!map[index].occupied && !map[index].deleted){
                int insertAt = (firstTombstone == -1) ? index : firstTombstone;
                map[insertAt].key = key;
                map[insertAt].value = value;
                map[insertAt].occupied = true;
                map[insertAt].deleted = false;
                OCCUPIED++;
                if(getLF() > LF_THRESHOLD){
                    reHash();
                }
                return;
            } else if(!map[index].occupied && map[index].deleted && firstTombstone == -1) {
                firstTombstone = index;
            }     
            index = (index + 1) % SIZE;

            if(index == start) {
                if(firstTombstone == -1) return;
                map[firstTombstone].key = key;
                map[firstTombstone].value = value;
                map[firstTombstone].occupied = true;
                map[firstTombstone].deleted = false;
                OCCUPIED++;
                return;
            }   
        }
    }
    
    int get(int key) {
        int index = key % SIZE;
        int start = index;
        while(true){
            if(!map[index].occupied && !map[index].deleted){
                return -1;
            } else if(map[index].occupied && map[index].key == key){
                return map[index].value;
            } else {
                index = (index + 1) % SIZE;
                if(start == index) return -1;
            }
        }
    }
    
    void remove(int key) {
        int index = key % SIZE;
        int start = index;
        while(true){
            if(!map[index].occupied && !map[index].deleted) {
                return;
            } else if (map[index].occupied && map[index].key == key){
                map[index].occupied = false;
                map[index].deleted = true;
                OCCUPIED--;
                return;
            } else {
                index = (index + 1) % SIZE;
                if(index == start) return;
            }
        }
    }
};