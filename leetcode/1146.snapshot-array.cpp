class SnapshotArray {
public:
    int snap_id;
    vector<unordered_map<int,int>> mySnap;
    SnapshotArray(int length) {
        mySnap.resize(length);
        snap_id = 0;
    }
    
    void set(int index, int val) {
        mySnap[index][snap_id] = val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    // O(snap_id)
    int get(int index, int snap_id) {
        //this loop handle the case when multiple snap called without calling set in 
        // between as in snap we just increasing snap_id not actually putting any data to map
        //Eg: ["SnapshotArray","set",{"snap","snap","snap"},"get","snap","snap","get"]
        // [[1],[0,15],[],[],[],[0,2],[],[],[0,0]]

        while(snap_id>=0) {
            if(mySnap[index].find(snap_id)==mySnap[index].end()) {
                snap_id--;
            } else {
                return mySnap[index][snap_id];
            }
        }
         return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */