class Solution {
public:
     
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int x[4] = {0,0,-1,1};
        int y[4] = {1,-1,0,0};
        priority_queue<vector<int>, vector<vector<int>>,greater<>> pq;
        vector<vector<int>> vis(n, vector<int>(n,0));
        pq.push({grid[0][0],0,0});
        //vis[0][0]=1;
        int ans =0;
        while(!pq.empty()){
            vector<int> a = pq.top();
            pq.pop();
            int dist = a[0];
            ans = max(ans,dist);
            int i = a[1];
            int j = a[2];
            if (vis[i][j]) {
                continue;
            }
            vis[i][j]=1;
            if(i==n-1 && j==n-1) return dist;
            for(int k=0; k<4; k++){
                int ni = i+x[k];
                int nj = j+y[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && !vis[ni][nj]){
                    pq.push({max(dist,grid[ni][nj]),ni,nj});
                }
            }
        }
        return -1;
    }
};