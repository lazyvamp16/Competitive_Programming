//Shuffle Party
// round 930 Div 2 A
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--)
    {
    int n;
    int mod = 1e9+1;
    cin>>n;
    if(n==1 ) cout << 1 << endl;
    else{
        int i=1;
        while(!(n>= pow(2,i) && n<pow(2,i+1)))
        {
            i++;
        }
        int ans= pow(2,i);
        cout << ans % mod << endl;
    }
    }
}
/*
    int n,r,i;
    cin>>n;
    vector<int>v(n,1);
    for(i=2; i<=n;i++)
    {
        if(i%2==0) r= i/2;
        else{
            for(r=n/2; r>=1; r--){
                if(i%r==0) break;
            }
        }
        v[i-1]=v[r-1];
        v[r-1] = i;
    }
    for (int i=0;i<n; i++) {
        if (v[i]==1) cout << i+1 << endl;
    }
}
*/