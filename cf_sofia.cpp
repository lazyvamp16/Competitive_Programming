// C. Sofia and the Lost Operations
// Codeforces Round 950 (Div. 3)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n,i;
        bool ans = true;
        cin >>n;
        vector<int> v(n,0);
        for(int j=0;j<n; j++) cin >> v[j];
        for(i=0;i<n-2;i++){
            if( __gcd(v[i],v[i+1]) > __gcd(v[i+1],v[i+2])) {
                v.erase(v.begin()+i+1);
                break;
            }
        }
        if(i>0 && (__gcd(v[i],v[i+1]) < __gcd(v[i-1],v[i]))) ans = false;
        for(;i<n-2;i++){
            if( (__gcd(v[i],v[i+1]) > __gcd(v[i+1],v[i+2])))  {
                ans = false;
                break;
            }
        }
        if(ans) cout << "yes"<<endl;
        else cout << "no"<<endl;
    }
}