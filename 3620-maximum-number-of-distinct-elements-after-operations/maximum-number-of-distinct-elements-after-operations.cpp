class Solution {
public:
    int maxDistinctElements(vector<int>& v, int k) {
        int n= v.size();
        if(k>=(n/2)) return n;
        sort(v.begin(),v.end());
        unordered_set<int> s;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(!s.count(v[i]-k)){
                s.insert(v[i]-k);
                v[i] = v[i]-k;
            }
            else {
                if(v[i-1]+1>v[i]+k) {
                    v[i] = v[i-1];
                    cnt++;
                    continue;
                }
                v[i] = v[i-1]+1;
                s.insert(v[i]);
            }
        }
        /*
        s.clear();
        int cnt =0;
        for(int i: v){
            cout << i << " ";
            if(s.count(i)) cnt++;
            else s.insert(i);
        }
        */
        return n-cnt;
    }
};