class Solution {
public:
    string minWindow(string s, string t) {
        int s1 = s.size();
        int s2 = t.size();
        if(s2>s1) return "";
        unordered_map<char,int> m1,m2;
        for(char c:t) m2[c]++;
        int l=0;
        int r=0;
        bool flag = false;
        int an1=0;
        int have=0;
        int need = m2.size();
        int an2=0;
        int ans = INT_MAX;
        while(r<s1){
            m1[s[r]]++;

            if (m2.count(s[r])) {
                if (m1[s[r]] == m2[s[r]]) {
                    have++;
                }
            }
            r++;
            // if(!flag && r-l>=s2){
            //     flag = true;
            //     for(auto i:m2){
            //         if(!m1.count(i.first) || m1[i.first] < i.second) {
            //             flag = false;
            //             break;
            //         }
            //     }
            // }
            while(have==need){
                if(r-l<ans){
                    ans = r-l;
                    an1=l;
                    an2=r;
                }
                if(m2.count(s[l]) && m1[s[l]]==m2[s[l]])have--;
                m1[s[l++]]--;
            }
        }
        if(ans==INT_MAX) return "";
        return s.substr(an1,an2-an1);
    }
};