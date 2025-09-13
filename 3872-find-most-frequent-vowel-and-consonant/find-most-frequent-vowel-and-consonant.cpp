class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> vowels,consonants;
        for(char c : s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                vowels[c]++;
            }
            else{
                consonants[c]++;
            }
        }
        int ans =0;
        for(auto i : vowels){
            ans = max(ans,i.second);
        }
        int add = 0;
        for(auto i : consonants){
            add = max(add,i.second);
        }
        return ans + add;
    }
};