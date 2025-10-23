class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> ans;
        unordered_set<string> st,anss;
        for(int i=0; i<=n-10; i++){
            string t = s.substr(i,10);
            if(st.count(t) && !anss.count(t)) {
                ans.push_back(t);
                anss.insert(t);
            }
            else st.insert(t);
        }
        return ans;
    }
};