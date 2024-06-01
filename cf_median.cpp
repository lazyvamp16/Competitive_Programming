// A. Median of an Array
// Codeforces Round 936 (Div. 2)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        int c =1;
        vector<int> v;
        cin >> n;
        for(int i =0; i<n; i++){
            int x; 
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        if(n%2==1) m = n/2;
        else m = (n/2) -1;
        for(int i = m+1; i<n;i++){
            if (v[i]==v[m]) c++;
            else break;
        }
        cout << c << endl;
    }
}
