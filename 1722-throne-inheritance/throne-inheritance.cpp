class ThroneInheritance {
public:
    unordered_map<string,vector<string>> adj;
    string start;
    unordered_set<string> d;
    ThroneInheritance(string kingName) {
        start = kingName;
    }
    
    void birth(string p, string c) {
        adj[p].push_back(c);
    }
    
    void death(string n) {
        d.insert(n);
    }

    void dfs(string start, unordered_set<string>&vis, unordered_map<string,vector<string>> &adj, vector<string>& ans){
        vis.insert(start);
        if(!d.count(start)) ans.push_back(start);
        for(auto i : adj[start]){
            if(!vis.count(i)){
                dfs(i,vis,adj,ans);
            }
        }

    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        unordered_set<string> vis;
        dfs(start,vis,adj,ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */