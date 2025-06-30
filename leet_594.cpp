#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

// Leetcode 594. Longest Harmonious Subsequence

int main()
{
    vector<int> nums{1,3,2,2,5,2,3,7};
    unordered_map<int,int> m;
    int ans = 0;
    int count = 0;
    for(int i:nums){
        m[i]++;
    }
    for(auto i:m){
        int next_number = i.first+1;
        if(m.find(next_number)!=m.end()){
            count = i.second + m[next_number];
            ans = max(ans,count);
        }
    }
    cout << ans;
}