// D. Gold Rush
// round 871 Div 4
#include<bits/stdc++.h>
using namespace std;


bool dfs(int x, int t){
    if(x==t) return true;
    if(x%3 != 0) return false;
    return (dfs(x/3,t) || dfs(2*(x/3),t));
}

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n>> m;
        if(n==m) cout << "YES" <<endl;
        else if(n%3!=0) cout << "NO" <<endl;
        else{
            if(dfs(n/3,m) || dfs(2*(n/3),m)) cout << "YES" <<endl;
            else cout << "NO" <<endl;
        } 
    }   
}