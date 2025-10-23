class Solution {
public:
    bool hasSameDigits(string s){
        int n = s.size();
        for(int i=0; i<n-2; i++){
            string t="";
            //cout << s << endl;
            for(int j=1; j<s.size(); j++){
                int d= (s[j]-'0'+s[j-1]-'0')%10;
                //cout << d << " ";
                t+=d+'0';
            }
            s = t;
        }
        //cout << s;
        if(s.size()<2) return false;
        if(s[0]==s[1]) return true;
        return false;
    }
};