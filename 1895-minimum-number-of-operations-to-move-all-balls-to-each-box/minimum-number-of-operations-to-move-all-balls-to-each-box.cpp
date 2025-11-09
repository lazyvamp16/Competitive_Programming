class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> v;
        int n=boxes.size();
        vector<int> ans(n,0);

        for(int i=0; i<n; i++){
            if(boxes[i]=='1') v.push_back(i);
        }

        for(int i=0; i<n; i++){
            for(int j:v) ans[i]+=abs(i-j);
        }
        
        return ans;
    }
};