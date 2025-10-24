class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.back();
        vector<int> dp(n+3,0);
        dp[nums[0]]=1;
        dp[nums[0]+1]=1;
        int maxi =1;
        for(int i=1; i<nums.size(); i++){
            dp[nums[i]+1] = 1 + dp[nums[i]];
            dp[nums[i]] = 1+dp[nums[i]-1];
            maxi = max({maxi,dp[nums[i]],dp[nums[i]+1]});
        }
        return maxi;
    }

};