class Solution {
public:
    bool f(int i, int sum, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(sum==target) return true;
        if(sum>target) return false;
        if(i==-1) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool take = f(i-1,sum+nums[i],target,nums,dp);
        bool not_take = f(i-1,sum,target,nums,dp);
        return dp[i][sum] = (take || not_take);
    }
    bool canPartition(vector<int>& nums){
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        sum/=2;
        int n =nums.size()-1;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return(f(n-1,0,sum,nums,dp));
    }
};