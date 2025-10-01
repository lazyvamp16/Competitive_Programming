class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l =0; 
        int r =0;
        int n = nums.size();
        long long prod=1;
        int cnt =0;
        while(r<n){
            while(l<r && prod*nums[r]>=k){
                prod/=nums[l];
                l++;
                
            }
            prod*=nums[r];
            if(prod<k)cnt += r-l+1;
            r++;
        }
        return cnt;
    }
};