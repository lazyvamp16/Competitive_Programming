#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits> // for INT_MAX
using namespace std;

int main() {
  int n,m;
  cin >> n>> m;
  vector<vector<vector<int>>> adj(n+1);
  for(int i=0; i<m; i++){
    int x,y,z; 
    cin >>x>>y;
    adj[x].push_back({y,1});
    adj[y].push_back({x,1});
  }

  vector<int> dis(n+1, INT_MAX);
  vector<int> parent(n+1, 0);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  
  pq.push({0, 1});
  dis[1]=0;
  parent[1] =1;
  while(!pq.empty()){
    int dist = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (dist != dis[node]) continue;   //skip outdated entries

    for(vector<int> i : adj[node]){
      if(i[1]+dist < dis[i[0]]){
        dis[i[0]] = i[1]+dist;
        parent[i[0]] = node;
        pq.push({dis[i[0]],i[0]});
      }
    }
  }
  if(dis.back()==INT_MAX) cout << "IMPOSSIBLE";
  else{
    cout << dis.back()+1 << endl;

    vector<int> ans;
    int k = n;
    while(parent[k]!=k){
      ans.push_back(k);
      k = parent[k];
    }
    ans.push_back(k);
    for(auto i=ans.rbegin(); i!=ans.rend(); i++) cout << *i<< " ";
  }
}