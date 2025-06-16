class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int low=nums[0];
        for(int i=1; i<nums.size();i++){
            if(nums[i]<=low){
                low = nums[i];
            }
            else ans = max(ans,(nums[i]-low));   
        }

        /*
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]>high && i>j) {
                high = nums[i];
                while(j<i) {
                    if(nums[j]<low){
                        low = nums[j];
                    }
                    j++;
                }
                ans = max(ans,(high-low));
            }
        }
        if (ans==0) return -1;
        */
        return(ans);
    }
};