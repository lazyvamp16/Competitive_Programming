// Codeforces Round 1044 (Div. 2)
// Problem B

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
        int n;
        cin >>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        long long ans =0;
        // if(n%2==0){
        //     for(int i=0; i<n; i+=2) ans+=v[i];
        // }
        // else{
        //     for(int i=0; i<n; i+=2) ans +=v[i];
        // }
        for(int i=0; i<n; i+=2) ans +=v[i];
        cout << ans << endl;
    }
    return 0;
}