class Solution {
public:
    int maximumLength(vector<int>& arr, int kl) {
        int n= arr.size();
        vector<vector<int>> dp(n,vector<int>(kl+1,1)); 
        //for(int i=0; i<=kl; i++) dp[0][i]=1;
        int maxi =1;
        for(int i=1; i<n; i++){
            for(int x=0; x<i; x++){
                for(int j=0; j<=kl; j++){
                    if(arr[i]==arr[x]){
                        dp[i][j]= 1 + dp[x][j];
                    }
                    else {
                        //dp[i][j] = max(dp[i][j],dp[x][j]);
                        if(j>0) dp[i][j]=max(dp[i][j],1+dp[x][j-1]);
                    } 
                    maxi = max(maxi,dp[i][j]);
                }
            }
        }
        for(int i=0; i<n;i++) cout <<dp[i][0] <<" ";
        return maxi;
    }
};