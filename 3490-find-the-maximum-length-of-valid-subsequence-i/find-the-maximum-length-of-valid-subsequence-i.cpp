class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int allEven=0, allOdd=0, alternate=1; 
        //int oddEven=0, evenOdd=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0) {
                allEven++;
            }
            else if(nums[i]%2==1) {
                allOdd++;
            }
            if(i>0 && ((nums[i]+nums[i-1])%2==1)) {
                alternate++;
            }
            
            //if(i%2==0 && nums[i]%2==0) {evenOdd++;}
            //else if(i%2==1 && nums[i]%2==1) {evenOdd++;}
            
            //if(i%2==0 && nums[i]%2==1) {oddEven++;}
            //else if(i%2==1 && nums[i]%2==0) {oddEven++;}
        }
        int ans = max(allEven,allOdd);
        //int ans2 = max(evenOdd, oddEven);
        return max(ans,alternate);
    }
};