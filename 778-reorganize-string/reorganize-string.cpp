class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;
        priority_queue<pair<int,char>> pq;
        for(char c: s){
            m[c]++;
        }
        for(auto i: m){
            pq.push({i.second,i.first});
        }
        string ans;
        pair<int,char> prev = {-1,'a'};
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.second);
            if(prev.first>1) pq.push({prev.first-1,prev.second});
            prev = p;
        }
        return (ans.size()==s.size())?ans:"";
        
    }
};