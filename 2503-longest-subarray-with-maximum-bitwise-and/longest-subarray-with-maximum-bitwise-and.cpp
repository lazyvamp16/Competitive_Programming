class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //int mx = *max_element(nums.begin(),nums.end());
        int cnt =0, ans = 1;
        int mx = 1;
        for(int i:nums){
            if(i>mx) {
                ans=1;
                mx=i;
                cnt=1;
            }
            else if(mx==i) {
                cnt++;
                ans = max(ans,cnt);
            }   
            else cnt=0;
        }
        return ans;
    }
};