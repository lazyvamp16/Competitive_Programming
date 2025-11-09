class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        multiset<int> s;
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){

                if(j>0) matrix[i][j] = matrix[i][j-1]^matrix[i][j];
                if(i>0) matrix[i][j] = matrix[i-1][j]^matrix[i][j];
                if(j>0 && i>0) matrix[i][j] = matrix[i][j]^matrix[i-1][j-1];
                s.insert(matrix[i][j]);
            }
        }
        auto it =s.end();
        for(int i=0; i<k; i++){
            it--;
        }
        int ans = *it;
        return ans;
    }
};