class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.length()<k){
            int n = s.length();
            for(int i=0; i<n; i++){
                //cout << "in ";
                if(s[i]=='z') s.push_back('a');
                else s.push_back(char(s[i]+1));
            }
            //cout << s << endl;
        }
        return s[k-1];
    }
};