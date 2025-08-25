class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int num = n+m-1;
        //if(m==1) num = n;
        //else if(n==1) num = m;
        //else  num = ((m*n)/2) +1; 

        vector<int> ans;
        for(int i=0; i<num; i++){
            vector<int> v;
            for(int j=0; j<m; j++){
                if(j>i) break;
                for(int k=0; k<n; k++){
                    if(k>i) break;
                    if(j+k==i) v.push_back(mat[j][k]);
                }
            }
            if(i%2 ==0) reverse(v.begin(),v.end());
            for (int x : v) ans.push_back(x);
        }
        return ans;
    }
};

