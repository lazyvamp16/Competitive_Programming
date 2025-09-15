class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
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
            
            bool flag = true;
            for(char x : s){
                if(!flag) break;
                for(char c : brokenLetters){
                    if(c==x) {
                        cnt++;
                        flag=false;
                        break;
                    }
                }
            }
        }
        return t.size()-cnt;
    }
};