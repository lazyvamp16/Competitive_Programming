// Stickogon
// Codeforces Round 940 (Div. 2) A

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        int count =0;
        cin >> n;
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            cin >> x;
            m[x]++;
        }
        for(auto i: m){
            if(i.second > 2) count= count + i.second/3;
        }
        cout << count << endl;
    }
}