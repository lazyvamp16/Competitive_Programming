#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{   
    int n;
    int MOD = 1e9+7;
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=6; j++){
            if(i>=j) dp[i] = (dp[i]+ dp[i-j])%MOD;
        }
    }
    cout << dp[n];
}