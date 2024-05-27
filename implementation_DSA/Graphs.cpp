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



// Time Complexity: O(N+E) 
// Space Complexity: O(N) + O(N) 
// Auxiliary Space Complexity:  O(N) (recursion stack)
void topodfs(int node, unordered_map<int,vector<int>> adj,vector<int> &vis,  stack<int> &st )
{
    vis[node]=1;
    for(auto i : adj[node])
    {
        if(!vis[i]) topodfs(i,adj,vis,st);
    }
    st.push(node);
}

vector<int> toposort(int n, unordered_map<int,vector<int>> adj)
{
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0; i<n; i++)
    {
        if (!vis[i]) topodfs(i,adj,vis,st);
    }
    vector<int> ans;
    while(!st.empty()) 
    {
        ans.push_back(st.top());
        st.pop();
    }
    return(ans);
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
                auto record = st.find(make_pair(dist[neighbours.first],neighbours.first));
                if (record!=st.end()) st.erase(record);
                dist[neighbours.first]=nodeDistance + neighbours.second;
                st.insert(make_pair(dist[neighbours.first],neighbours.first));
            }
        }
    }

    return (dist) ;
}


vector<int> print_shortest_path()
// from 1 to n
{
    int  n=5;
    int m=6;
    vector<vector<int>> edges = {{1,2,2}, {2,5,5}, {2,3,4}, {1,4,1},{4,3,3},{3,5,1}};
    vector<pair<int,int>> adj[n+1];
    vector<int> parent(n+1,1);
    for(auto it: edges) 
    {
        adj[it[0]].push_back(make_pair(it[1],it[2]));
        adj[it[1]].push_back(make_pair(it[0],it[2]));
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    vector<int> d(n+1,1e9);
    d[1] = 0;
    pq.push(make_pair(0,1));
    while(!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto i:adj[node])
        {
            int adjnode=i.first;
            int adjdist=i.second;
            if(dis+adjdist<d[adjnode])
            {
                d[adjnode] = dis + adjdist;
                pq.push(make_pair(d[adjnode],adjnode));
                parent[adjnode]= node; 
            }
        }
    }
    if(d[n]==1e9) return {-1};
    vector<int> path;
    int node = n;
    while(parent[node]!=node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    return path;
}



//floyd warshall algorithm TC: O(N^3)
//Find the city with the smallest number of neighbours at a threshold distance
void findcity()
{
    int n = 4, m = 4;
    int distanceThreshold = 4;
    vector<vector<int>> edges = {{0, 1, 3},{1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    // {from,to,weight}
    
    vector<vector<int>> dist (n,vector<int>(n,INT_MAX));
    for(auto it : edges) {
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }
    for(int i=0; i<n;i++) dist[i][i]=0;
    
    for(int k=0; k<n;k++){
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                if(dist[i][k]==INT_MAX || dist[i][k]==INT_MAX) continue;
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    int mincnt = n;
    int ans =-1;
    for(int i=0; i<n;i++){
        int cnt=0;
        for(int j=0; j<n;j++){
            if(dist[i][j]<=distanceThreshold) {
                cnt++;
            }
        }
        if(cnt<=mincnt){
            mincnt = cnt;
            ans = i;
        }
    }
    cout << ans;
}


// prims algorithm Minimum spanning tree
// TC = 2 O(E log E)
// SC = E + V
int spanningTree(int V, vector<vector<int>> adj[])
    {
        // min heap
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        vector<int> vis(V,0);
        vector<pair<int,int>> mst; // storing the edges of the MST
        int sum = 0;
        pq.push({0,0,-1}); // weight, node, parent
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it[0];
            int node = it[1];
            int parent = it[2];
            if(!vis[node]) {
                vis[node] = 1;
                sum+=wt;
                //mst.push_back({node,parent});
                for(auto it: adj[node])
                {
                    int adjwt = it[1];
                    int adjnode = it[0];
                    if(!vis[adjnode]) pq.push({adjwt,adjnode,node});
                }
            }
        }
        //for(auto i:mst) cout << i.first << " " << i.second << endl;
        return(sum);
    }

int main()
{   
    Graph g;
    g.addEdge(5,2,1);
    g.addEdge(5,0,1);
    g.addEdge(4,0,1);
    g.addEdge(4,1,1);
    g.addEdge(2,3,1);
    g.addEdge(3,1,1);
    // g.printAdj();

    int n=6;
    unordered_map<int,vector<int>> adj= g.adj;

    //vector<int> bfs = bfs_graph(n,adj);
    //vector<int> dfs = dfs_graph(n,adj);
    //vector<int> topo = toposort(n,adj);
    //for(int i:topo) cout << i << " ";
    //vector<int> path = print_shortest_path();
    //for(int i:path) cout << i << " ";
    findcity();
}


