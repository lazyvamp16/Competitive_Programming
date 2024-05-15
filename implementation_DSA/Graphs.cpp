#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
        unordered_map <int, vector<int>> adj; //Adjacency map
        
        void addEdge(int u, int v, bool direction)
        {   
            adj[u].push_back(v);
            if (direction==0) adj[v].push_back(u); // Undirected -> Bi-directional
        }

        void printAdj()
        {
            for (auto i : adj){
                cout << i.first << " -> " ;
                for (auto j : i.second){
                    cout << j << ", ";
                }
                cout << endl;
            }
        }
};

//TC = O(n) + O(2E)
//SC = O(3n) = O(n)
vector<int> bfs_graph(int n, unordered_map<int, vector<int>> adj)
{
    vector<int> bfs;
    vector<int> v(n,0);
    v[0]=1;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int node= q.front();
        bfs.push_back(node);
        q.pop();
        for(auto i: adj[node])
        {
            if(v[i]==0){
                q.push(i);
                v[i]=1;              
            }

        }
    }
    return(bfs);
}


//TC = O(n) + O(2E) for undirected 
//TC = O(n) + O(E) for directed
//SC = O(3n) = O(n)
void dfs(vector<int> &ans, int node, unordered_map<int,vector<int>> adj, int v[])
{
    v[node] = 1;
    ans.push_back(node);
    for(auto i : adj[node])
    {
        if (!(v[i]))
        {
            dfs(ans, i, adj, v);
        }
    }
}

vector<int> dfs_graph(int n, unordered_map<int,vector<int>> adj)
{
    int v[n] = {0};
    int start = 0;
    vector<int> ans;
    dfs(ans,start,adj,v);
    return ans;
}



//TC = O(ElogV)
//SC = O(N+E)
vector<int> dijkstra (vector<vector<int>> &vec, int vertices, int edges, int source)
{
    //create adjacency list
    unordered_map <int, list<pair<int,int>>> adj;
    for(int i=0; i<edges; i++ ) 
    {
        int u= vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> dist(vertices,INT_MAX);
    
    //sets store data in ascending order of distance
    //set of type (distance, node)
    set<pair<int,int>> st;

    dist[source] =0;
    st.insert(make_pair(0,source));

    while(!st.empty())
    {
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;
        st.erase(top);

        for(auto neighbours : adj[topNode])
        {
            if(nodeDistance + neighbours.second < dist[neighbours.first])
            {
                dist[neighbours.first]=nodeDistance + neighbours.second;
                auto record = st.find(make_pair(dist[neighbours.first],neighbours.first));
                if (record!=st.end()) st.erase(record);
                st.insert(make_pair(dist[neighbours.first],neighbours.first));
            }
        }
    }

    return (dist) ;
}





int main()
{   
    Graph g;
    g.addEdge(0,2,0);
    g.addEdge(2,4,0);
    g.addEdge(0,1,0);
    g.addEdge(0,3,0);
    // g.printAdj();

    int n=5;
    unordered_map<int,vector<int>> adj= g.adj;

    //vector<int> bfs = bfs_graph(n,adj);
    vector<int> dfs = dfs_graph(n,adj);
    for(int i:dfs) cout << i << " ";
}


