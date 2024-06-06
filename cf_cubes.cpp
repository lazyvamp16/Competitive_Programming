// B. Choosing Cubes
// Codeforces Round 950 (Div. 3)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n,f,k,t;
        cin >> n >> f >> k;
        vector<int> v(n,0);
        for(int i=0;i<n;i++) cin >> v[i];
        int fav = v[f-1];
        sort(v.begin(),v.end(),greater<int>());
        if(v[k-1] > fav) cout << "NO"<< endl;
        else if(k<n && v[k-1]==fav && v[k]==fav) cout << "MAYBE"<<endl;
        else cout << "YES"<<endl;
    }
}