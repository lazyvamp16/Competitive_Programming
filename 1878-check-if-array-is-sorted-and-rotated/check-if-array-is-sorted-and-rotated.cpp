class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        int n = nums.size();
        for(int i=0; i<n-1;i++){
            if(nums[i]>nums[i+1]) cnt++;
        }
        if(nums.size()<=2) return true;
        else if(cnt==0) return true;
        else if(cnt==1 && nums.back()<=nums[0]) return true;
        return false;
    }
};