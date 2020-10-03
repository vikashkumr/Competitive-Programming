class LRUCache {
public:
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> hm;
    int capacity;
    
    void refreshPos(int key, int value) {
        l.erase(hm[key]);
        l.push_front({key,value});
        hm[key] = l.begin();
    }
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(hm.count(key) == 0) return -1;
        refreshPos(key, (*hm[key]).second);
        return (*hm[key]).second;
        
    }
    
    void put(int key, int value) {
        if(hm.count(key)) {
            refreshPos(key, value);
        } else {
            l.push_front({key,value});
            hm[key] = l.begin();
            if(hm.size() > capacity) {
                hm.erase(l.back().first);
                l.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */