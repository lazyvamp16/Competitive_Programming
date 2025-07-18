#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0; i<n;i++) cin >> v[i];
        int level = 1;
        int curr = v[k-1];
        sort(v.begin(),v.end());
        int i;
        for(i=0;i<n;i++){
            if(v[i]==curr) break;
        }
        int time = 1;
        bool ans=true;
        for(;level<=v.size(); level++){
            curr = v[i];
            if(level>curr) {
                ans = false;
            }
            if(time==(v[i+1]-v[i])) {
                i++;
                time =1;
            }
            else time++;
        }
        if(ans) cout << "YES" <<endl;
        else cout << "NO" << endl;
    }
}