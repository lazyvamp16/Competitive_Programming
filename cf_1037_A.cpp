#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        int ans = INT_MAX;
        cin >> x;
        while(x>0){
            int d = x%10;
            x=x/10;
            ans = min(ans,d);
        }
        cout << ans << endl;
    }
}