#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm>
#include <stack>
using namespace std;

// for backtracking -> DFS not BFS

int start = -1;
int nex = -1; //next is a keyword dont use as global variable

bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &parent){
    for(int neighbour : adj[node]){
        if(!vis[neighbour]) {
            vis[neighbour] =1;
            parent[neighbour] = node;
            // only return when true, not when false
            //return dfs(neighbour, adj, vis, parent);
            if (dfs(neighbour, adj, vis, parent)) return true;
        }
        else if(parent[node]!=neighbour){
            //cout << node << " " << neighbour;
            //for(int i: parent ) cout << i << " ";
            start = neighbour;
            nex = node;
            return true;
        }
    }
    return false;;
}

int main() {
    int n,m,x,y;
    cin >> n>> m;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(n+1,0);
    vector<int> parent(n+1,-1);
    for(int i=1; i<=n; i++){
        parent[i] = i;  
    }
    int cnt=2;
    stack<int> st;
    for(int i=1; i<=n; i++){
        if(!vis[i]) {
            vis[i]=1;
            if(dfs(i,adj,vis,parent)){
                
                while(nex!=start){
                    cnt++;
                    st.push(nex);
                    nex = parent[nex];
                }
                cout << cnt << endl << start << " "; 
                while(!st.empty()){
                    cout << st.top() << " ";
                    st.pop();
                }
                cout << start << endl;
                return 0;
            }
            // WRONG: let other components get explored
            // else{
            //     cout << "IMPOSSIBLE" << endl;
            //     return 0;
            // }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}