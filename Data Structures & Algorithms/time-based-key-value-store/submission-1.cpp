class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "";
        vector<pair<int,string>> ar = mp[key];
        int lo = 0, hi = ar.size()-1, mid,ans;
        if(ar[0].first>timestamp) return "";
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(ar[mid].first<=timestamp) {
                ans = mid;
                lo = mid+1;
            }
            else  hi = mid - 1;
        }
        return ar[ans].second;
    }
};
