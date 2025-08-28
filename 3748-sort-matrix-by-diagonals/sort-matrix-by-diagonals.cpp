class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0; i<n; i++){
            vector<int> temp;
            for(int j=i, k=0; j<n; j++,k++){
                temp.push_back(grid[j][k]);
                sort(temp.begin(),temp.end(),greater<int>());
            }
            for(int j=i, k=0; j<n; j++,k++){
                grid[j][k] = temp[k];
            }
        }
        for(int i=0; i<n-1; i++){
            vector<int> temp;
            for(int j=i, k=n-1; j>=0; j--,k--){
                //cout << grid[j][k];
                temp.push_back(grid[j][k]);
                sort(temp.begin(),temp.end(),greater<int>());
            }
            int m =0;
            for(int j=i, k=n-1; j>=0; j--,k--){
                grid[j][k] = temp[m++];
            }
        }

        return grid;
    }
};