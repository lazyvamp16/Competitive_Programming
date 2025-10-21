class Solution {
public:

    int f(int i, int j, string w1, string w2, 
      vector<vector<int>>& dp){

        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j] != -1) return dp[i][j];
        if(w1[i]==w2[j]){
            return dp[i][j] =f(i-1,j-1,w1,w2,dp); 
        }
        else{
            int ans = min(f(i-1,j,w1,w2,dp),f(i,j-1,w1,w2,dp));
            ans = min(ans,f(i-1,j-1,w1,w2,dp));
            return dp[i][j] =1 + ans;
        }

    }

    int minDistance(string w1, string w2) {
        int m = w1.size();
        int n = w2.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(m-1,n-1,w1,w2,dp);
    }
};