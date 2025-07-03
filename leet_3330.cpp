#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

// Leetcode 3330. Find The Original Typed String I

int main()
{
    string word = "abbcccc";
    //string word = "ere";
    int n = word.length();
    int ans = 1;
    for(int i=1;i<n;i++){
        if(word[i]==word[i-1]) ans++;
    }
    cout << ans;
}

    // This approach doesnt work for cases like aabaa
    // where letters same letters arent consecutive
    /*
    unordered_map<char,int> m;
    for(char i:word){
        m[i]++;
    }
    int ans = 1;
    for(auto i:m){
        if(i.second>1){
            ans = ans + i.second - 1;
        }
    }
    cout<<ans;
    */

