#include <iostream>
#include <vector>
#include <map>
#include <queue> 
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;

vector<int> toposort(vector<vector<int>>&adj, vector<int> indegree){
    vector<int> topo;
    queue<int> q;
    int n = indegree.size();
    for(int i=1; i<n; i++) if(indegree[i]==0) {
        q.push(i);
        topo.push_back(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i: adj[node]){
            indegree[i]--;
            if(indegree[i]==0) {
                q.push(i);
                topo.push_back(i);
            }
        }
    }
    return topo;
}

int main(){
    int n,m,x,y;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1);
    for(int i=0; i<m; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    vector<int>topo = toposort(adj,indegree);
    vector<int> dp(n+1,0);
    queue<int> q;
    vector<int> vis(n+1,0);
    for(int i: topo){
        for(int nei:adj[i] ){
            dp[nei] = max(dp[nei],dp[i]+1);
        }
    }
    cout << *max_element(dp.begin(),dp.end())<<endl;
    return 0;
}