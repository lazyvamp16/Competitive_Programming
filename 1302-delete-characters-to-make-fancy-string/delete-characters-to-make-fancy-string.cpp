class Solution {
public:
    string makeFancyString(string &s) {
        string ans;
        char prev = s[0];
        ans.push_back(prev);
        int cnt = 1;
        for(int i=1; i<s.length(); i++){
            if(s[i]==prev){
                cnt++;
                if(cnt<3){
                    ans.push_back(prev);
                }
            }
            else {
                prev = s[i];
                cnt=1;
                ans.push_back(prev);
            }
        }
        return ans;
    }
};