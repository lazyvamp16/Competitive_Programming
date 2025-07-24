class Solution {
private:
    bool isValid(int n, string begin, string end){
        int cnt = 0;
        for(int i=0; i<n; i++){
            if (begin[i]!=end[i]) cnt++;
        }
        if(cnt==1) return true;
        return false;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.length();
        int ans = 1;
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end()) return 0;
        // same as if (!words.count(endWord)) return 0;
        unordered_set<string> vis;
        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        while(!q.empty()){
            int l = q.size();
            for(int i=0; i<l; i++){
                string curr = q.front();
                q.pop();
                if(curr==endWord) return ans;
                // for(string word : wordList){
                //     if(vis.count(word)==0 && isValid(n,curr,word)) {
                //         q.push(word);
                //         vis.insert(word);
                //     }
                // }
                for(int j=0; j<n; j++){
                    string temp = curr;
                    for(char c = 'a'; c<='z'; c++){
                        temp[j]= c;
                        if(words.count(temp) && !vis.count(temp)){
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};