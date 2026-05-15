class Solution {
public:
    int findMin(vector<int>& nums) {
        //return (*min_element(nums.begin(),nums.end()));
        int ans = nums[0];
        if(nums[0]<nums.back()) return ans;
        int left =0;
        int right = nums.size()-1;

        while(left<right){
            int mid = left + (right-left)/2;
            if(nums[mid]>nums[right]){
                ans = nums[mid];
                left = mid+1;
            }
            else {
                ans = nums[mid];
                right = mid;
            }
        }
        return nums[left];
    }
};