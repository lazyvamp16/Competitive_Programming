class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n =days.size();
        vector<int> dp(days.size()+1,0);
        int d = *max_element(days.begin(),days.end());
        int w = n;
        int m=days.size();
        for(int i=days.size()-1; i>=0; i--){
            int w = days.size();
            int m=days.size();
            for(int x=i; x<days.size(); x++){
                if((days[x]-days[i])<7) w = x;
                if((days[x]-days[i])<30) m = x;
                else break;
            }
            w++;
            m++;
            dp[i] = min({
                costs[0] + dp[i + 1],
                costs[1] + (w <= n ? dp[w] : 0),
                costs[2] + (m <= n ? dp[m] : 0)
            });
        }
        
        return dp[0];
    }
};