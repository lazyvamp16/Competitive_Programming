class Solution {
public:
    int countTriples(int n) {
        int ans =0;
        for(int i=1; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sq = i*i + j*j ;
                double root = sqrt(sq);
                if(root == floor(root) && root<=n) {
                    //cout << i << " "<<j << " " <<root << " "<< sq <<endl;
                    ans+=2;
                }
            }
        }
        return ans;
    }
};