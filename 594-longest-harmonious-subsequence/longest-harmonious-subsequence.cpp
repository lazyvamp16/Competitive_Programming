class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = 0;
        int count = 0;
        for(int i:nums){
            m[i]++;
        }
        for(auto i:m){
            int next_number = i.first+1;
            if(m.find(next_number)!=m.end()){
                count = i.second + m[next_number];
                ans = max(ans,count);
            }
        }
        return ans;
    }
};