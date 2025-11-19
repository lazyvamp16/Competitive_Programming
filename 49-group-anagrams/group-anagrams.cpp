class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& temp) {
        vector<string> strs = temp;
        for(string &s : strs){
            sort(s.begin(),s.end());
        }
        unordered_map<string,vector<int>> m;
        int index=0;
        for(string s:strs){
            m[s].push_back(index);
            index++;
        }
        vector<vector<string>> ans;
        for(auto i:m){
            vector<string> v;
            for(int j : i.second){
                v.push_back(temp[j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};