class Solution {
public:
    int compareVersion(string ve1, string ve2) {
        int cnt1=1, cnt2=1;
        vector<int> v1,v2;
        for(char i: ve1){
            if(i=='.') cnt1++;
        }
        for(char i: ve2){
            if(i=='.') cnt2++;
        }

        string s="";
        for(char c : ve1){
            if(c=='.') {
                v1.push_back(stoi(s));
                s="";
            }
            else{
                s+=c;
            }
        }
        if(s!="") v1.push_back(stoi(s));
        s="";
        for(char c : ve2){
            if(c=='.') {
                v2.push_back(stoi(s));
                s="";
            }
            else{
                s+=c;
            }
        }
        if(s!="") v2.push_back(stoi(s));

        for(int i=0; i<min(cnt1,cnt2); i++){
            if(v1[i]==v2[i]) continue;
            if(v1[i]>v2[i]) return 1;
            else return -1;
        }
        if(cnt2>cnt1) {
            for(int i=cnt1; i<cnt2; i++){
                if(v2[i]!=0) return -1;
            }
        }
        if(cnt1>cnt2) {
            for(int i=cnt2; i<cnt1; i++){
                if(v1[i]!=0) return 1;
            }
        }
        return 0;
    }
};