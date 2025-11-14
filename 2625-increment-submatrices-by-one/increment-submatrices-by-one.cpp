class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n,vector<int>(n));
        for(auto v : queries){
            for(int i=v[0]; i<=v[2]; i++){
                for(int j=v[1]; j<=v[3]; j++){
                    mat[i][j]++;
                }
            }
        }
        return mat;
    }
};