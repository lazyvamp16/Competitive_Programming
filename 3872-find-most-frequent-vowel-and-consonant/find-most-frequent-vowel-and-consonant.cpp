class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> vowels,consonants;
        int co=0, v=0;
        for(char c : s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                vowels[c]++;
                v = max(v,vowels[c]);
            }
            else{
                consonants[c]++;
                co = max(co,consonants[c]);
            }
        }
        return co + v;
    }
};