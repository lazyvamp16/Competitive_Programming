class Solution {
public:
    int maxArea(vector<int>& nums) {
        int l = 0; 
        int r = nums.size()-1;
        int ans =0;
        while(l<r){
            ans = max(ans,min(nums[l],nums[r]) * (r-l));
            if(nums[l]<nums[r]){
                l++;
            }
            else r--;
        }
        return ans;
    }
};