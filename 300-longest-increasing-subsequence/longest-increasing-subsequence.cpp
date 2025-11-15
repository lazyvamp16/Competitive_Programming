class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        /*
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1; i>=0; i--){
            for(int prev=i-1; prev>=-1; prev--){
                int not_take = dp[i+1][prev+1];
                int take = 0;
                
                if(prev==-1 || nums[prev] < nums[i]){
                    take = max(take,(dp[i+1][i+1] + 1));
                    
                }
                dp[i][prev+1] = max(take,not_take);
            }
        }
        return dp[0][0];
        */

        /*
        int ans =1;
        vector<int> dp(n+1,1);
        //dp[0]=1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
        */

        vector<int> len;
        for(int i : nums){
            if(len.empty() || len.back()<i) len.push_back(i);
            else{
                auto it = lower_bound(len.begin(),len.end(),i);
                *it = i;
            }
        }
        return len.size();
    }
};