class TaskManager {
public:
    unordered_map<int,int> us;
    unordered_map<int,int> pri;
    set<vector<int>,greater<>> s;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto i: tasks){
            int user = i[0];
            int id = i[1];
            int pr = i[2];
            s.insert({pr,id,user});
            pri[id]=pr;
            us[id]=user;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        s.insert({priority,taskId,userId});
        pri[taskId]=priority;
        us[taskId]=userId;
    }
    
    void edit(int taskId, int newPriority) {
        s.erase(s.find({pri[taskId],taskId,us[taskId]}));
        s.insert({newPriority,taskId,us[taskId]});
        pri[taskId]=newPriority;
    }
    
    void rmv(int taskId) {
        s.erase(s.find({pri[taskId],taskId,us[taskId]}));
        pri.erase(taskId);
        us.erase(taskId);
    }
    
    int execTop() {
        if(s.size()==0) return -1;
        auto it = s.begin();
        int taskId=(*it)[1];
        int ans = (*it)[2];
        s.erase(it);
        pri.erase(taskId);
        us.erase(taskId);
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */