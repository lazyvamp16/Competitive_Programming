class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        /*
        string word = "";
        vector<string> t;
        for(char i : text){
            if(i==' '){
                t.push_back(word);
                word="";
            }
            else{
                word+=i;
            }
        }
        if(word!="") t.push_back(word);
        int cnt =0;
        for(string s : t){
        */
        int cnt =0;
        int bigcnt =1;
        bool flag = true;
        for(char x:text){
            if(x==' '){
                flag = true;
                bigcnt++;
                continue;
            }
            if(!flag) continue;
            for(char c : brokenLetters){
                if(c==x){
                    cnt++;
                    flag=false;
                    break;
                }
            }
        }
        return bigcnt-cnt;
    }
};