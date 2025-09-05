#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
  string x,y;
  cin >> x >> y;
  int cnt = 0;
  int n = x.size();
  int m = y.size();
  vector<vector<int>> dp(n+1, vector<int>(m+1,0));
  
  int i=0;
  stack<char> st;
  while(i<n){
    int j=0;
    while(j<m){
      if(x[i]==y[j]) dp[i+1][j+1] = dp[i][j]+1;
      else dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]); 
      j++;
    }
    i++;
  }
  
  i=n; 
  int j=m;
  while(i>0 && j>0){
    if(x[i-1]==y[j-1]) {
      st.push(x[i-1]);
      i--;
      j--;
    }
    else if(dp[i][j-1]>=dp[i-1][j]) j--;
    else i--;
  }
  
  while(!st.empty())
  {
    cout << st.top();
    st.pop();
  }
  
  return 0;
}
  
