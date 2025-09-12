class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt =0;
        vector<char> vowels={'a','e','i','o','u'};
        for(char c : s) for(char v : vowels) if(v==c) cnt++;
        return (cnt!=0);
    }
};