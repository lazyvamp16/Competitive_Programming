// Codeforces Round 1032 (Div. 3)
// Problem B

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<char> a(n);
        unordered_map<char,int> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]]++;
        }
        bool ans = false;
        for(int i=1;i<n-1;i++){
            if(m[a[i]]>1) ans = true;
        }
        if (ans) cout <<"YES" << endl;
        else cout << "NO" << endl;
    }
}