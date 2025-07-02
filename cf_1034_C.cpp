// Codeforces Round 1034 (Div. 3)
// Problem C

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        vector<int> ans(n,1);
        int pre = v[0];
        vector<int> suf(n, 0);
        suf[n-1] = v.back();
        for(int i=n-2;i>=0;i--){
            suf[i] = max(suf[i+1], v[i]);
        }
        for(int i=1;i<n-1;i++){
            if(pre<v[i] && v[i]<suf[i+1]){
                ans[i] = 0;
            }
            pre = min(pre,v[i]);
        }
        for(int i: ans){
            cout << i;
        }
        cout << endl;
    }
}
