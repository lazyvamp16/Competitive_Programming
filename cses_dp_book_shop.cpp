#include <iostream>
#include <vector>
#include <map>
#include <queue> 
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;


int f(int i,int w, vector<int> cost, vector<int> pages, vector<vector<int>> &dp){
    if(i==-1) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

    int take =0;
    int not_take = f(i-1,w,cost,pages,dp);
    if(w>=cost[i]) {
        take = pages[i] + f(i-1,w-cost[i],cost,pages,dp);
    }
    return dp[i][w]=max(take,not_take);
}

int main() {
    int n,w;
    cin >> n>>w;
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    vector<int>cost(n);
    vector<int> pages(n);
    for(int i=0; i<n; i++){
        cin >> cost[i];
    }
    for(int i=0; i<n; i++){
        cin >> pages[i];
    }

    for(int i =0; i<n; i++){
        for(int j=0; j<=w; j++){
            if(i==0) {
                if(j>=cost[i]) dp[i][j] = pages[0];
                else dp[i][j]=0;
            }
            else{
                int take =0;
                int not_take = dp[i-1][j];
                if(j>=cost[i]) take = pages[i] + dp[i-1][j-cost[i]];
                dp[i][j] = max(take,not_take);
            }
        }
    }
    //cout << f(n-1, w, cost,pages,dp) << endl;
    cout << dp[n-1][w];
}