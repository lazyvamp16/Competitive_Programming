// Codeforces Round 1044 (Div. 2)
// Problem A

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,x;
        map<int,int> m;
        cin >>n;
        for(int i=0; i<n; i++){
            cin>>x;
            m[x]++;
        }
        bool ans = false;
        for(auto i: m){
            if(i.second>1) ans = true;
        }
        if(ans) cout << "YES"<<endl;
        else cout << "NO"<<endl;
    }
    return 0;
}