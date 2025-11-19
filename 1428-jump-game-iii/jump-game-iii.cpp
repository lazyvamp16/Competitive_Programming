class Solution {
public:
    bool canReach(vector<int>& arr, int start){
        int n = arr.size();
        vector<int> vis(n);
        queue<int> q;
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(arr[node]==0) return true;
            int next = node+arr[node];
            int prev = node-arr[node];
            if(next<n && !vis[next]) {
                q.push(next);
                vis[next]=1;
            }
            if(prev>=0 && !vis[prev]) {
                q.push(prev);
                vis[prev]=1;
            }
        }
        return false;
    }
};