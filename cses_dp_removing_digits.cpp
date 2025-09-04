#include <iostream>
#include <vector>
#include <map>
#include <queue> 
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;


int f(int n, vector<int> &dp){
    int temp = n;
    if(n<10) return 1;
    if(dp[n]!=-1) return dp[n];
    int mini = INT_MAX;
    while(temp>0){
        int digit = temp%10;
        temp/=10;
        if(digit==0) continue;
        mini= min(mini, f(n-digit,dp));
    }
    return dp[n] = (1+mini);
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    cout << f(n,dp) << endl;
}