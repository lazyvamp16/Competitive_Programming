class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9+7;
        vector<int> dp(n+1);
        dp[1]=1;
        long long add=0;
        for(int i=2; i<=n; i++){
            //int add=0; // WHY NOT ? 
            if(i>delay) add = (add+dp[i-delay])%MOD;
            if(i>forget) {
                add =(add-dp[i-forget])%MOD;
                if(add < 0) add += MOD; // ensure non-negative
            }
            dp[i] =add%MOD;
        }
        int ans =0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};
