class Solution {
public:

    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> v(101,0);
        vector<int> ans;
        int cnt =0;
        for(int i:nums){
            if(v[i]==1) {
                cnt++;
                ans.push_back(i);
                if(cnt==2) break;
            }
            else v[i]=1;
        }
        return ans;
    }
};