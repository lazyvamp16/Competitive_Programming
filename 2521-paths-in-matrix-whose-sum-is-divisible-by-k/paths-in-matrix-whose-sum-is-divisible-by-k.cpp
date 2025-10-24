class Solution {
public:

    const int MOD = 1e9+7;

    int f(int i, int j, int m, int n, int sum,int k,
    vector<vector<int>>& grid, 
    vector<vector<vector<int>>>& dp){
        if(i==m-1 && j==n-1 && sum==0) return 1;
        if(i==m || j==n) return 0;
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        int right = 0, down =0;
        if(j+1<n) right = f(i,j+1,m,n,(sum+grid[i][j+1])%k,k,grid,dp)%MOD;
        if(i+1<m) down = f(i+1,j,m,n,(sum+grid[i+1][j])%k,k,grid,dp)%MOD;
        return dp[i][j][sum] = (right+down)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return f(0,0,m,n,grid[0][0]%k,k,grid,dp);
    }
};