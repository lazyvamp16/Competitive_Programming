// A. Problem Generator
// Codeforces Round 950 (Div. 3)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,t;
    cin >> t;
    while(t--)
    {
        int c =0;
        string s;
        unordered_map<char,int> mp;
        cin >> n >> m >>s;
        for(int i=0;i<n; i++) mp[s[i]]++;
        for(int i=0;i<m;i++){
            for(char i = 'A'; i<='G'; i++ ){
                if(mp[i]>0) mp[i]--;
                else c++;
            }
        }
        cout << c << endl;
    }
}