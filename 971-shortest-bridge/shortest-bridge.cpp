class Solution {
public:
    int r[4] = {-1,1,0,0};
    int c[4] = {0,0,-1,1};

    void dfs(int i, int j, int m, int n,
    vector<vector<int>>& vis,
    vector<vector<int>>& grid,
    vector<pair<int,int>> &s)
    {
        vis[i][j]=1;
        s.push_back({i,j});
        for(int x=0; x<4; x++){
            int ni = i+r[x];
            int nj = j+c[x];
            if(ni<m && nj<n && ni>=0 && nj>=0 
                && grid[ni][nj] && !vis[ni][nj]) {
                dfs(ni,nj,m,n,vis,grid,s);
            }
        }
    }


    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i,j; 
        vector<pair<int,int>> set1,set2;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j]){
                    dfs(i,j,m,n,vis,grid,set1);
                    goto done;
                }
            }
        }
        done:;
        for(;i<m; i++){
            for(;j<n; j++){
                if(!vis[i][j] && grid[i][j]){
                    dfs(i,j,m,n,vis,grid,set2);
                    goto done1;
                }
            }
            j=0;
        }
        done1:;
        //cout << set1.size();
        //cout << set2.size();
        int ans =INT_MAX;
        for(auto i : set1){
            for(auto j:set2){
                int dist = abs(i.first-j.first)+abs(i.second-j.second);
                ans = min(ans,dist);
            }
        }
        return ans-1;
    }
};