#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void dfs(long node, vector<long>&vis,  unordered_map<long,vector<long>> &adj){
    //cout << node;
    vis[node]=1;
    for(long i : adj[node]){
        if(!vis[i]) {
            dfs(i,vis,adj);
        }
    }   
}

int main() {
    long n,m,x,y;
    unordered_map<long,vector<long>> adj;
    cin >> n>> m;
    vector<long> vis (n+1,0);
    for(long i=0; i<m; i++){
        cin >> x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<long> ans;
    long cnt =-1;
    for(long i=1; i<=n; i++){
        if(!vis[i]) {
            ans.push_back(i);
            cnt++;
            //cout << i;
            dfs(i,vis,adj);
        }
    }
    cout << cnt << endl;
    if (cnt!=0) {
        for(long i=1; i<ans.size(); i++){
            cout << ans[i-1] << " " << ans[i] << "\n"; 
        }
    }
}