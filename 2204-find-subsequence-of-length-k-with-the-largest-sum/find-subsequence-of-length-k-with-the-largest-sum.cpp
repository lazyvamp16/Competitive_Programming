class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>ans;
        vector<int> v = nums;
        int n = v.size();
        sort(v.begin(),v.end(),greater<int>());
        multiset<int> ms(v.begin(),v.begin()+k);
        for(int i : nums){
            if(ms.find(i)!=ms.end()) {
                ans.push_back(i);
                ms.erase(ms.find(i));
            }
        }
        return ans;
    }
};