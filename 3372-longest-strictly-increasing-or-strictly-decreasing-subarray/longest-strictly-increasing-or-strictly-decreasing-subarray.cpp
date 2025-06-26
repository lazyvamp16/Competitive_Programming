class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int increasing_cnt=1,decreasing_cnt=1,ans=1,final_ans=1;
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                increasing_cnt++;
                decreasing_cnt=1;
            }
            else if(nums[i]<nums[i-1]){
                increasing_cnt=1;
                decreasing_cnt++;
            }
            else {
                increasing_cnt = 1;
                decreasing_cnt = 1 ;
            }
            ans = max(increasing_cnt, decreasing_cnt);
            final_ans = max(final_ans,ans);
        }
    return final_ans;
    }
};