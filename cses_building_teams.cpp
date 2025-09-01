#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm>
using namespace std;

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
    queue<int> q;
    vector<int> team(n+1,0);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            q.push(i);
            vis[i]=1;
            team[i] = 1;
            while(!q.empty() || q.size()>1e6){
                int node = q.front();
                int tm = team[node];
                q.pop();
                for(int neighbour : adj[node]){
                    if(!vis[neighbour]) {
                        team[neighbour] = (tm==1) ? 2 : 1;
                        vis[neighbour] =1 ;
                        q.push(neighbour);
                    }
                    else {
                        if(team[neighbour]==tm) {
                            cout << "IMPOSSIBLE" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout << team[i] <<" ";
    }
    return 0;
}