class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char,vector<int>> m;
        vector<int> v(n);
        //unordered_set<char> s;
        for (int i=0; i<n; i++){
            char c = s[i];
            v[i]= m.size();
            //s.insert(c);
            m[c].push_back(i);
        }
        /*
        for(int i : v) cout << i << " ";
        int ans =0;
        for(auto i : m){
            vector<int> ind = i.second;
            ans += (v[ind.back()]-v[ind[0]]);
        }
        return ans;
        */
        int ans =0;
        for (auto &p : m) {
            vector<int> &ind = p.second;
            if (ind.size() < 2) continue;
            int L = ind.front();
            int R = ind.back();
            if (R - L <= 1) continue;  // no middle
            // count distinct characters between L and R
            bool seen[26] = {0};
            for (int i = L + 1; i < R; i++) seen[s[i] - 'a'] = true;
            // add distinct count
            for (int i = 0; i < 26; i++) ans += seen[i];
        }
        return ans;
    }
};
// 0 1 2 3 4 5 6 7 8
// c k a f n a f q o
// 0 1 2 3 4 5 5 5 6

// f -> 3,6        : 2
// a -> 2,5        : 3