class Solution {
public:
    string modifyString(string &s) {
        char prev,next;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='?'){
                if(i==0) prev='*';
                else prev = s[i-1];
                if(i==s.size()-1) next = '*';
                else next = s[i+1];
                for(char c ='a'; c<='z'; c++){
                    if(c==prev || c==next) continue;
                    s[i]=c;
                }
            }
        }
    return s;
    }
};