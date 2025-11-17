class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int cnt=0;
        int m = grid.size();
        int n= grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2) {
                    q.push({i,j,0});
                }
                else if(grid[i][j]==1) cnt++;
            }
        }
        vector<int> x{0,0,-1,1};
        vector<int> y{1,-1,0,0};
        int ans =0;
        while(!q.empty()){
            vector<int> top = q.front();
            q.pop();
            int i=top[0];
            int j=top[1];
            int t=top[2];
            ans = max(ans,t);
            for(int k=0; k<4; k++){
                int ni=i+x[k];
                int nj=j+y[k];
                if(ni>=0 && ni<m && nj>=0 && nj<n
                && grid[ni][nj]==1){
                    cnt--;
                    grid[ni][nj]=2;
                    q.push({ni,nj,t+1});
                }
            }
        }
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(grid[i][j]==1) return -1;
        //     }
        // }
        return (cnt==0)?ans:-1;
    }
};