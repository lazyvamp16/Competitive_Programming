class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [&](const vector<int> &a, const vector<int> &b){
                return a[1]<b[1];
            }
        );
        vector<int> ans;
        set<int> s;

        // for(auto v : intervals){
        //     if(v[1]-v[0]==1){
        //         if(!s.count(v[0])) {
        //             ans.push_back(v[0]);
        //             s.insert(v[0]);
        //         }
        //         if(!s.count(v[1])) {
        //             ans.push_back(v[1]);
        //             s.insert(v[1]);
        //         }
        //     }
        // }

        // for(auto v : intervals){
        //     int cnt =0;
        //     int ind1= -1;
        //     for(int i=v[1]; i>=v[0];i--){
        //         if(s.count(i)) {
        //             cnt++;
        //             if(cnt==2) break;
        //             ind1 = i;
        //         }
        //     }
        for (auto &v : intervals) {
            int l = v[0], r = v[1];
            int cnt = 0, ind1 = -1;
            auto it = s.upper_bound(r); // first > r
            while (it != s.begin()) {
                --it;
                int x = *it;
                if (x < l) break;
                cnt++;
                if (cnt == 1) ind1 = x;
                if (cnt == 2) break;
            }
            if(cnt==1) {
                for(int i=v[1]; i>=v[0];i--){
                    if(i==ind1) continue;
                    else {
                        ans.push_back(i);
                        s.insert(i);
                        break;
                    }
                }
            }
            if(cnt==0){
                ans.push_back(v[1]);
                ans.push_back(v[1]-1);
                s.insert(v[1]);
                s.insert(v[1]-1);
            }
        }
        return ans.size();
    }
};
