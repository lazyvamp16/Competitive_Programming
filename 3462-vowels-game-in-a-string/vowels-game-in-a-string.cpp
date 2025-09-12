class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt =0;
        unordered_set<char> vowels={'a','e','i','o','u'};
        for(char c : s){
            if(vowels.count(c)!=0) cnt++;
        }
        if(cnt==0) return false;
        return true;
    }
};