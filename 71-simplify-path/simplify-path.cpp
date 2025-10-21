class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string s;
        vector<string> v;
        for(int i=0; i<n; i++){
            if(path[i] =='/'){
                if(i!=0 && path[i-1]=='/') continue;
                if(!s.empty() && s!=".") v.push_back(s);
                s="";
            }
            else s+=path[i];
        }
        if(!s.empty() && s!=".") v.push_back(s);
        string ans = "";
        int cnt =0;
        for(int i=v.size()-1; i>=0;){
            if(v[i]==".."){
                i--;
                cnt++;
                if(i<0) {
                    if(ans.empty()) return "/";
                    else return (ans);
                }
            }
            else if(cnt>0){
                i--;
                cnt--;
            } 
            else {
                ans = "/"+v[i]+ans;
                i--;
            }
        }
        cout << v.size();
        if(ans.empty()) return "/";
        else return (ans);
    }
};