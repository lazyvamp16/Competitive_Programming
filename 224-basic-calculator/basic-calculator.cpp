class Solution {
public:
    int calculate(string s) {
        bool sign = false;
        long long ans =0;
        int num;
        stack<pair<long long ,int>> sta;
        string st = "";
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])){
                while(i<s.size() && isdigit(s[i])){
                    st += s[i];
                    i++;
                }
                i--;
                num = stoi(st);
                cout << num << endl;
                st="";
                if(!sign) {
                    ans += num;
                }
                else {
                    ans-=num;
                }
                sign = false;
            }
            
            else if(s[i]==' ') continue;
            else if(s[i]=='(') {
                sta.push({ans,sign});
                ans =0;
                sign=false;
            }
            else if(s[i]==')') {
                if(sta.top().second) ans = sta.top().first-ans;
                else ans =sta.top().first + ans;
                sta.pop();
                sign = false;
            }
            else if(s[i]=='-') {
                if(sign==true) sign = false;
                else sign = true;
            }
            //else sign = false;
            
        }
        return ans;
    }
};

