class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        vector<vector<int>> ans;
        set<pair<int,int>> vis_a,vis_p;
        queue<pair<int,int>> a,p;

        int m = h.size();
        int n = h[0].size();
        for (int i = 0; i < n; i++) {          
            p.push({0, i});
            vis_p.insert({0, i});
            a.push({m - 1, i});
            vis_a.insert({m - 1, i});
        }
        for (int i = 0; i < m; i++) {          
            p.push({i, 0});
            vis_p.insert({i, 0});
            a.push({i, n - 1});
            vis_a.insert({i, n - 1});
        }

        int x[4] = {0,0,-1,1};
        int y[4] = {1,-1,0,0};
        while(!a.empty()){
            int r = a.front().first;
            int c = a.front().second;
            a.pop();
            for(int i=0; i<4; i++){
                int nr = r+x[i];
                int nc = c+y[i];
                if(nr<m && nc<n && nr>=0 && nc>=0 &&
                   vis_a.count({nr,nc})==0 && 
                   h[nr][nc]>=h[r][c])
                {
                    vis_a.insert({nr,nc});
                    a.push({nr,nc});
                }
            }
        }
        while(!p.empty()){
            int r = p.front().first;
            int c = p.front().second;
            p.pop();
            for(int i=0; i<4; i++){
                int nr = r+x[i];
                int nc = c+y[i];
                if(nr<m && nc<n && nr>=0 && nc>=0 &&
                   vis_p.count({nr,nc})==0 && 
                   h[nr][nc]>=h[r][c])
                {
                    vis_p.insert({nr,nc});
                    p.push({nr,nc});
                }
            }
        }

        for(auto i:vis_a){
            if(vis_p.count(i)) ans.push_back({i.first,i.second});
        }

        return ans;
    }
};