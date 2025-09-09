#include <iostream>
#include <vector>
#include <map>
#include <queue> 
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;


int main() {
    int n,w;
    cin >> n>>w;
    vector<int> dp(w+1,INT_MAX);
    vector<int>cost(n);
    for(int i=0; i<n; i++){
        cin >> cost[i];
    }
    dp[0]=0;
    for(int i =0; i<=w; i++){
        for(int j=0; j<n; j++){
            int take = INT_MAX;
            if (cost[j]<=i && dp[i-cost[j]]!=INT_MAX) take = 1 + dp[i-cost[j]];
            dp[i] = min(dp[i], take);
        }
    }
    if(dp[w]==INT_MAX) cout << -1<<endl;
    else cout << dp[w] <<endl;
}