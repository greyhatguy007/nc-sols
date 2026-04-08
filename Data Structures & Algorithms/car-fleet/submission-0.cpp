class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size(),ans=0;
        float maxtime = 0;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({position[i],speed[i]});
        sort(v.begin(),v.end());
        for(int i=n-1;i>=0;i--){
            float time = (float) (target-v[i].first)/v[i].second;
            if(maxtime<time){
                ans++;
                maxtime = time;
            }
        }
        return ans;
    }
};
