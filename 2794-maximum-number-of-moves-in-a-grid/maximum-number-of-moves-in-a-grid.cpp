class Solution {
public:
    int f(int i, int j, int m, int n, vector<vector<int>>& grid,
    vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        //int ud=0,bd=0,right=0;
        int ans =0;
        if(i-1>=0 && j+1<n && grid[i-1][j+1]>grid[i][j]) 
            ans = max(ans,1+f(i-1,j+1,m,n,grid,dp));
        if(i+1<m && j+1<n && grid[i+1][j+1]>grid[i][j]) 
            ans = max(ans,1+f(i+1,j+1,m,n,grid,dp));
        if(j+1<n && grid[i][j+1]>grid[i][j]) 
            ans = max(ans,1+f(i,j+1,m,n,grid,dp));
        return dp[i][j] = ans;

    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans =0;
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0; i<m; i++){
            ans = max(ans,f(i,0,m,n,grid,dp));
        }
        return ans;
    }
};