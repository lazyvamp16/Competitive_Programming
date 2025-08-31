class Solution {
public:
    const int MOD = 1e9+7;
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp, int prev, int m, int n){
        if( i<0 || j<0 || i>=m || j>=n ){
            return 0;
        }
        
        if(i==0 && j==0) return 1;

        if(dp[i][j][prev+1] != -1) return dp[i][j][prev+1];
        long long up,left;
        up = f(i-1, j, grid, dp,0,m,n);
        left = f(i, j-1, grid, dp,1,m,n);
        if(grid[i][j]==1 && prev!=-1) {
            if(prev==0){
                return dp[i][j][prev+1]=left%MOD;
            }
            else{
                return dp[i][j][prev+1]=up%MOD;
            }
        }      
        long long ans = left + up;
        return dp[i][j][prev+1] = ans % MOD;
    }
    
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp;
        dp.assign(m, vector<vector<int>>(n, vector<int>(3, -1)));
        return f(m-1,n-1,grid,dp,-1,m,n);
    }
};