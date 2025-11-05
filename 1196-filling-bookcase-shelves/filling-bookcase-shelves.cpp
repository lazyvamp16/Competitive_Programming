class Solution {

public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();

        vector<int> dp(n,1e9);
        dp[0] = books[0][1];

        for(int i=0;i<n;i++){
            int w = books[i][0];
            int maxh = books[i][1];
            int j = i-1;
            for(;j>=0;j--){
                dp[i] = min(dp[i],dp[j]+maxh);
                w += books[j][0];
                maxh = max(maxh,books[j][1]);
                if(w>shelfWidth) break;
            }
            // cout<<j<<endl;
            if(j==-1) if(w<=shelfWidth) dp[i] = min(dp[i],maxh);
        }
        // for(int it : dp) cout<<it<<" ";

        return dp[n-1];
    }
};