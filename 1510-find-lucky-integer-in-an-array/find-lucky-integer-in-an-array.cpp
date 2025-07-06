class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> m;
        int ans = -1;
        for(int i:arr){
            m[i]++;
        }
        for (auto x: m){
            if(x.first == x.second && x.first>ans){
                ans = x.first;
            }
        }
        return ans;
    }
};