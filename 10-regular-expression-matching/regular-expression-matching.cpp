class Solution {


public:

    bool f(int i, int j, int n, int m, 
    string s, string p, vector<vector<int>>& dp){

        if(i==-1 && j==-1) return true;
        if(j==-1) return false;
        if(i==-1 && p[j]=='*') return f(i,j-2,n,m,s,p,dp);
        if(i==-1) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans = false;
        if(s[i]==p[j] || p[j]=='.'){
            ans = f(i-1,j-1,n,m,s,p,dp);
        }
        else if(p[j]=='*'){
            char prev = p[j-1];
            if(prev=='.' || prev==s[i]) ans = f(i,j-2,n,m,s,p,dp) || f(i-1,j,n,m,s,p,dp);
            else return dp[i][j] =f(i,j-2,n,m,s,p,dp);
        }
        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        // bool flag = false;
        // char c;
        // for(int i=0; i<s.size(); i++){
        //     if(!flag){
        //         c = p[i];
        //         if(p[i]=='*') {
        //             flag = true;
        //             c = p[i-1];
        //         }
        //     }
        //     if(c=='.') continue;
        //     if(s[i]!=c) return false;
        // }

        int n = s.size();
        int m = p.size();


        vector<vector<int>> dp(n,vector<int> (m,-1));
        bool ans = false;
        return f(n-1,m-1,n,m,s,p,dp);
    }
};