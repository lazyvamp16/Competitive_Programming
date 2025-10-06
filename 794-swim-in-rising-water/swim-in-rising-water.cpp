class Solution {
public:
     
    int x[4] = {0,0,-1,1};
    int y[4] = {1,-1,0,0};

    bool dfs(int i, int j, int t, int n, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[i][j] =1;
        if(i==n-1 && j==n-1) return true;
        for(int k=0; k<4; k++){
            int ni = i+x[k];
            int nj = j+y[k];
            if(ni>=0 && nj>=0 && ni<n && nj<n && !vis[ni][nj]){
                if(grid[ni][nj]<=t) {
                    if (dfs(ni,nj,t,n,grid,vis)) return true;
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = 0; 
        int right = n*n;
        while(left<right){
            int mid = left + (right-left)/2;
            vector<vector<int>> vis(n,vector<int>(n,0));
            //if(grid[0][0]>mid) continue;
            if(dfs(0,0,mid,n,grid,vis) && grid[0][0]<=mid){
                right = mid;
            }
            else left = mid+1;
        }
        return left;
    }
};