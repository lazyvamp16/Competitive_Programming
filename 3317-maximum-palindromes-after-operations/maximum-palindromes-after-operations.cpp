class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        unordered_map<char,int> freq;
        vector<int> sizes;
        
        for(string word:words){
            sizes.push_back(word.size());
            for(char c:word){
                freq[c]++;
            }
        }

        sort(sizes.begin(),sizes.end());
        
        int pairs = 0;
        for(auto &f : freq){
            pairs += f.second/2;
        }
        
        int cnt =0;
        for(int i : sizes){
            if(i==1){
                cnt++;
                continue;
            }
            pairs -= i/2;
            if(pairs<0) break;
            cnt++;
        }
        return cnt;
    }
};

//