class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int start = n/2;
        for(int i=(-1*start); i<=start; i++){
            if(i==0 && n%2==0) continue;
            ans.push_back(i);
        }
        return ans;
    }
};