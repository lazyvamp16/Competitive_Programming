// Codeforces Round 1042 (Div. 3)
// Problem A

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,ans=0;
        cin >>n;
        vector<int> a(n),b(n); 
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        for(int i=0; i<n; i++){
            if(a[i] > b[i]){
                ans+=a[i]-b[i];
            }
        }
        cout << ans+1 << endl;
    }
    return 0;
}