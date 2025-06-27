// Codeforces Round 1032 (Div. 3)
// Problem A

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,pos,ans;
        cin >> n >> pos;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int mn = a[0];
        int mx = a[n - 1];
        if(pos<=mn) ans = mx-pos;
        else if(pos>=mx) ans = pos-mn;
        else ans = 2*min((pos-mn),(mx-pos)) + max((pos-mn),(mx-pos));
        cout << abs(ans) << endl;
    }
}