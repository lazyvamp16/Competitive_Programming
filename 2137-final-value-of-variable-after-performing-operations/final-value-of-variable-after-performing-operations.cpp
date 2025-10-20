class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int ans = 0;
        for(string s : op){
            if(s[0]=='+' || s.back()=='+'){
                ans++;
            }
            else ans--;
        }
        return ans;
    }
};