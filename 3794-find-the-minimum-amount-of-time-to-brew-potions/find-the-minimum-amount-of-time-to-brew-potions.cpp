class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        long long n= skill.size();
        long long m = mana.size();
        vector<long long> prev(n+1);
        for(long long i=0; i<m; i++){
            vector<long long> curr(n+1);
            
            //for(int x: prev) cout << x << " " ;
            //cout << endl;
            for(long long j=0; j<=n; j++){
                if(j==0) curr[0] = prev[1];
                else{
                    curr[j] = curr[j-1]+ (skill[j-1]*mana[i]);

                    if(j!=n && curr[j]<prev[j+1]) curr[j] = prev[j+1];
                }
            }
            for(long long k=n-1; k>=0;  k--){
                curr[k] = curr[k+1] - skill[k]*mana[i];

            }
                 
            prev = curr;
        }
        return prev.back();
    }
};