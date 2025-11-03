class Solution {
public:
    int minCost(string c, vector<int>& neededTime) {
        int n = neededTime.size();
        int i = 0;
        int ans =0;
        while(i<n){
            int curr = c[i];
            int cnt =0;
            int mx = 0;
            int sum =0;
            while(c[i]==curr){
                sum+=neededTime[i];
                mx = max(mx,neededTime[i]);
                i++;
                cnt++;
            }
            if(cnt>1) ans += (sum-mx);
            //i++;
        }
        return ans;
    }
};