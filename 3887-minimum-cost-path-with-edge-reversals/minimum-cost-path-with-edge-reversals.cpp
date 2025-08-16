class Solution {
private:
    vector<vector<vector<int>>> constructAdj(vector<vector<int>> &edges, int V) {
        vector<vector<vector<int>>> adj(V); 
        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u,2*wt});
        }
        return adj;
    }
    
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj = constructAdj(edges, n);
        priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> dist(n, INT_MAX);
        pq.push({0, 0});
        dist[0] = 0;
        while (!pq.empty()){
            int u = pq.top()[1];
            pq.pop();
            for (auto x : adj[u]){
                int v = x[0];
                int weight = x[1];
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        if(dist.back()==INT_MAX) return -1;
        return dist.back();
    }
};