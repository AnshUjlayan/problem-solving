class SnapshotArray {
private:
    int snapId;
    vector<unordered_map<int,int>> arr;
public:
    SnapshotArray(int length) {
        this->snapId = 0;
        this->arr = vector<unordered_map<int,int>>(length);
    }
    
    void set(int index, int val) {
        arr[index][snapId] = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        while(snap_id >= 0 && arr[index].find(snap_id) == arr[index].end())
            snap_id--;
        return !arr[index][snap_id] ? 0 : arr[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */