class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> ump;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        ump[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>& vec = ump[key];
        string result = "";
        int l = 0, r = vec.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int ts = vec[mid].first;
            if(ts <= timestamp) {
                l = mid + 1;
                result = vec[mid].second;
            }
            else {
                r = mid - 1;
            }
        }
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */