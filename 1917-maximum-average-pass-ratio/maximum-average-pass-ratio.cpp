class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int x) {
        int n = classes.size();
        priority_queue<pair<double,int>> pq;
        double ans=0;
        for(int i=0; i<n; i++){
            double a = classes[i][0];
            double b = classes[i][1];
            double increase = ((a+double(1))/(b+1)) - (double(a)/b);
            ans += a/b;
            pq.push({increase,i});
        }
        for(int i=0; i<x; i++){
            double increase = pq.top().first;
            int classa = pq.top().second;
            pq.pop();
            //cout << classa << " " << increase <<endl;
            ans+=increase;
            classes[classa][0]++;
            classes[classa][1]++;
            double a = classes[classa][0];
            double b = classes[classa][1];
            double new_incr = ((a+double(1))/(b+1)) - (double(a)/b);
            pq.push({new_incr,classa});
        }
        return ans/n;
    }
};