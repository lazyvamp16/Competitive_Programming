// Longest Increasing Subsequence

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums{0,1,0,3,2,3};
    int n=nums.size();
    vector<int> dp(n,1);
    int ans;
    for(int i=1; i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i] ){
                dp[i]=max(dp[i], 1 + dp[j]);
            }
        }
    }
    ans= *max_element(dp.begin(),dp.end());
    cout << ans;
}


