#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{   
    string str1,str2;
    cin >> str1 >> str2;
    int m= str1.size();
    int n = str2.size();

    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for(int i=0; i<=m; i++){
        for(int j =0; j<=n; j++){
            if (i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;
            else if(str1[i-1]!=str2[j-1]){
                int add = 1 + dp[i-1][j];
                int remove = 1 + dp[i][j-1];
                int replace = 1 + dp[i-1][j-1];
                dp[i][j] = min(min(add,remove),replace);
            }
            else dp[i][j] = dp[i-1][j-1];
        }
    }
    cout << dp[m][n];
}