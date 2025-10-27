class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n =bank.size();
        int ans =0;
        int prev_cnt =0;
        for(int i=0; i<n; i++){
            int cnt =0;
            for (char c : bank[i]){
                if(c=='1') cnt++;
            }
            if(cnt==0) continue;
            else {
                ans += prev_cnt*cnt;
                //cout << ans << " ";
                prev_cnt = cnt;
            }
        }
    return ans;
    }
};