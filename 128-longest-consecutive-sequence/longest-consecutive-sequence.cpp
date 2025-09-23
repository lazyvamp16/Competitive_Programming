class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n =nums.size();
        if (n<2) return n;
        int ans = 1;
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]-nums[i-1]==1) {
                cnt++;
                //cout <<cnt;
                ans = max(ans,cnt);
            }
            else cnt =1;
        }
        return ans;
    }
};