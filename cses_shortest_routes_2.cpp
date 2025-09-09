#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue> 
#include <algorithm>
#include <set>
#include <unordered_set>
#include <list>
#include <stack>
#include <climits>
using namespace std;

int main(){
    int n, e, q;
    long long x, y, z;
    vector<pair<long long, long long>> queries;
    cin >> n >> e >> q;
    vector<vector<long long>> adj(n+1, vector<long long>(n+1, LLONG_MAX));
    for(int i = 0; i < e; i++){
        cin >> x >> y >> z;
        adj[x][y] = min(adj[x][y], z);
        adj[y][x] = min(adj[y][x], z);
    }
    for(int i = 0; i < q; i++){
        cin >> x >> y;
        queries.push_back({x, y});
    }

    for(int i = 1; i <= n; i++) adj[i][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(adj[j][i] != LLONG_MAX && adj[i][k] != LLONG_MAX
                    && (adj[j][i] + adj[i][k] < adj[j][k])){
                    adj[j][k] = adj[j][i] + adj[i][k];
                }
            }
        }
    }
    for(auto i : queries){
        x = adj[i.first][i.second];
        if(x == LLONG_MAX) cout << -1 << endl;
        else cout << x << endl;
    }

    return 0;
}