class Solution {
public:
    int f(int i, int m, int n, vector<string>& strs, 
    vector<vector<vector<int>>>& dp){
        //cout << i<<endl;
        if(i<0) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int take = 0;
        int newm = m;
        int newn = n;
        for(char c:strs[i]){
            if(c=='0') newm--;
            else newn--;
        }
        if(newm>=0 && newn>=0) take = 1 + f(i-1,newm,newn,strs,dp);
        int not_take = f(i-1,m,n,strs,dp);
        return dp[i][m][n] = max(take,not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int x = strs.size();
        vector<vector<vector<int>>> dp(x,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return f(x-1,m,n,strs,dp);
    }
};