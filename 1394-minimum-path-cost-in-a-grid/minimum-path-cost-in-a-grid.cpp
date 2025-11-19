class Solution {
public:
    int f(int i, int y, int n,vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>> &dp){
        if(i==0) return grid[i][y];
        if(dp[i][y]!=-1) return dp[i][y];
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans, grid[i][y]+moveCost[grid[i-1][j]][y]+f(i-1,j,n,grid,moveCost,dp));
        }
        return dp[i][y]=ans;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ans = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0; i<n; i++){
            ans = min(ans,f(m-1,i,n,grid,moveCost,dp));
        }
        return ans;
    }
};