class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>m;

    void set(string key, string val, int t) {
        m[key].push_back({t,val});
    }
    
    string get(string key, int ts) {
        if(!m.count(key)) return "";
        auto &x = m[key];
        int left = 0;
        int right = x.size()-1;
        int ind = -1;
        int mid=0;
        while(left<=right){
            mid = left + (right - left)/2;
            if(x[mid].first>ts) right = mid -1;
            else if(x[mid].first<=ts) {
                ind = mid;
                left = mid+1;
            }
        }
        
        if(ind==-1) return "";
        return x[ind].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */