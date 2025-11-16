class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<char, char> next = {
            {'0', '1'}, 
            {'1', '2'}, 
            {'2', '3'}, 
            {'3', '4'}, 
            {'4', '5'},
            {'5', '6'}, 
            {'6', '7'}, 
            {'7', '8'}, 
            {'8', '9'}, 
            {'9', '0'}
        };
        unordered_map<char, char> prev = {
            {'0', '9'}, 
            {'1', '0'}, 
            {'2', '1'}, 
            {'3', '2'}, 
            {'4', '3'},
            {'5', '4'}, 
            {'6', '5'}, 
            {'7', '6'}, 
            {'8', '7'}, 
            {'9', '8'}
        };
        
        int ans = 0;
        unordered_set<string> vis(deadends.begin(), deadends.end());
        string start = "0000";
        if(vis.count(start) && target!=start) return -1;
        queue<pair<string,int>> q;
        q.push({start,ans});
        vis.insert(start);
        while(!q.empty()){
            string lock = q.front().first;
            ans = q.front().second;
            q.pop();
            if(lock==target) return ans;
            for(int i=0; i<4; i++){
                string nex=lock,pre=lock;
                nex[i] = next[nex[i]];
                pre[i] = prev[pre[i]];
                if(!vis.count(nex)) {
                    //if(nex==target) return ans+1;
                    q.push({nex,ans+1});
                    vis.insert(nex);
                }
                if(!vis.count(pre)) {
                    //if(pre==target) return ans+1;
                    q.push({pre,ans+1});
                    vis.insert(pre);
                }
                //cout << pre << " " << nex << " ";
            }
        }
        return -1;
    }
};