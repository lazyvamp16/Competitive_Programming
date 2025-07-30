class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int cnt =0, ans = 1;
        for(int i=0; i<nums.size(); i++){
            if(mx==nums[i]) {
                cnt++;
                ans = max(ans,cnt);
            }   
            else cnt=0;
        }
        return ans;
    }
};