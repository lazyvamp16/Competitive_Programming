class Solution {
public:
    string sortVowels(string &s) {
        //multiset<int> ms;
        vector<char> ms;
        vector<int> ind;
        unordered_set<char> vowels={'a','e','i','o','u',
                                    'A','E','I','O','U'};

        int i=0;
        for(char c : s){
            if(vowels.count(c)!=0){
                //ms.insert(int(c));
                ms.push_back(c);
                ind.push_back(i);
            }
            i++;
        }
        sort(ms.begin(),ms.end());
        i=0;
        for(auto c: ms){
            s[ind[i]] = c;
            i++;
        }
        return s;
    }
};