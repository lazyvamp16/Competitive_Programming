class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>prices(n,INT_MAX);
        vector<int> vis(n,0);
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        vector<vector<pair<int,int>>> adj(n);
        for(auto i: flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        //pq.push({k,price,src})
        pq.push({0,0,src});
        prices[src]=0;
        while(!pq.empty()){
            vector<int> v = pq.top();
            pq.pop();
            int c = v[0];
            int price = v[1];
            int node = v[2];
            if(node==dst) continue;
            if(c==k+1) continue;
            //if(price>prices[node]) continue;
            for(auto i: adj[node]){
                if(price+i.second < prices[i.first] ){
                    prices[i.first] = price+i.second;
                    pq.push({c+1,prices[i.first],i.first});
                }
            }
        }
        return (prices[dst]==INT_MAX)?-1:prices[dst];
    }
};