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
    vector<int> dp(w+1);
    vector<int>cost(n);
    for(int i=0; i<n; i++){
        cin >> cost[i];
    }
    dp[0]=1;
    for(int i =1; i<=w; i++){
        int sum =0;
        for(int j=0; j<n; j++){
            if(i>=cost[j]) sum = (sum+ dp[i-cost[j]])%int(1e9+7);
        }
        dp[i] = sum;
    }
    cout << dp[w] <<endl;
}