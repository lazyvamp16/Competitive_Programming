class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if(n<3) return false;
        int digitCnt=0, vowelCnt=0, consonantCnt=0;
        unordered_set<char> vowels{'a','e','i','o','u'};
        for(char ch: word){
            char i = tolower(ch);
            if(isalpha(i)) {
                if(vowels.find(i)!=vowels.end()) vowelCnt++;
                else consonantCnt++;
            }
            if(isdigit(i)) digitCnt++;
        }
        if(consonantCnt+vowelCnt+digitCnt != n) return false;
        if(consonantCnt<1 || vowelCnt<1) return false;\
        return true;
    }
};