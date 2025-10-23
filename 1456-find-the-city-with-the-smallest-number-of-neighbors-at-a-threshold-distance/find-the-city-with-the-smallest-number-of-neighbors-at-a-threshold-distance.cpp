class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {

        vector<vector<int>> mat(n,vector<int>(n,INT_MAX));
        for(auto i : edges){
            mat[i[0]][i[1]] = i[2];
            mat[i[1]][i[0]] = i[2];
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(i==j) mat[i][j]=0;
                    if(mat[i][k]!=INT_MAX && 
                       mat[k][j]!=INT_MAX &&
                       mat[i][k]+mat[k][j] < mat[i][j]){
                        mat[i][j] = mat[i][k]+mat[k][j];
                    }
                }
            }
        }

        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                //cout << mat[i][j] <<" ";
                if(i==j) continue;
                if(mat[i][j]<=th){
                    m[i]++;
                }
            }
            //cout << endl;
        }
        int mn = INT_MAX;
        int ans = 0;
        // for(auto i: m){
        //     //cout << i.second << endl;
        //     if(i.second<mn){
        //         mn = i.second;
        //         ans = i.first;
        //     }
        // }
        for(int i=0; i<n; i++){
            if(m[i]<=mn){
                mn = m[i];
                ans = i;
            }
        }
        return ans;
    }
};