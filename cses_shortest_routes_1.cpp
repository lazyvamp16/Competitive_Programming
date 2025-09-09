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

vector<long long> dijkstra (vector<vector<int>> &vec, int vertices, int edges, int source)
{
    //create adjacency list
    unordered_map <int, list<pair<int,int>>> adj;
    for(int i=0; i<edges; i++ ) 
    {
        int u= vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
    }

    vector<long long> dist(vertices,__LONG_LONG_MAX__);
    
    //sets store data in ascending order of distance
    //set of type (distance, node)
    set<pair<long long,long long>> st;

    dist[source] =0;
    st.insert(make_pair(0,source));

    while(!st.empty())
    {
        auto top = *(st.begin());
        long long nodeDistance = top.first;
        long long topNode = top.second;
        st.erase(top);

        for(auto neighbours : adj[topNode])
        {
            if(nodeDistance + neighbours.second < dist[neighbours.first])
            {
                auto record = st.find(make_pair(dist[neighbours.first],neighbours.first));
                if (record!=st.end()) st.erase(record);
                dist[neighbours.first]=nodeDistance + neighbours.second;
                st.insert(make_pair(dist[neighbours.first],neighbours.first));
            }
        }
    }
    return (dist) ;
}

int main(){
    int edges,vertices;
    vector<vector<int>> vec;
    cin >> vertices >> edges;
    for(int i =0; i<edges; i++){
        int x,y,z;
        cin >> x >> y >> z;
        vec.push_back({x,y,z});
    }
    vector<long long> ans = dijkstra(vec,vertices+1,edges,1) ;
    for(int i=1; i<=vertices; i++){
        cout << ans[i] << " " ;
    }
    return 0;
}