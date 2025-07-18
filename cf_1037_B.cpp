#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k, ans=0;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0; i<n;i++) cin >> v[i];
        int cnt =0;
        for(int i=0;i<n;i++){
            if(v[i]==0) cnt++;
            if(v[i]==1) cnt =0;
            if(cnt>=k) {
                ans++;
                cnt=0;
                i++;
            }
        }
        cout << ans << endl;
    }
}