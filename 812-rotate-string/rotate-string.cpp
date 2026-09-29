class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length()!=goal.length()) return false;
        string concated = s + s;
        if(concated.find(goal)==-1) return false;
        return true; 
    }
};