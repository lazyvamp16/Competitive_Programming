class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int allEven=0, allOdd=0, oddEven=0, evenOdd=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0) {allEven++;}
            else if(nums[i]%2==1) {allOdd++;}
            
            //if(i%2==0 && nums[i]%2==0) {evenOdd++;}
            //else if(i%2==1 && nums[i]%2==1) {evenOdd++;}
            
            //if(i%2==0 && nums[i]%2==1) {oddEven++;}
            //else if(i%2==1 && nums[i]%2==0) {oddEven++;}
        }

        int cnt=1;
        for(int i=1; i<nums.size();i++){
            if((nums[i]+nums[i-1])%2==1) cnt++;
        }
        
        int ans1 = max(allEven,allOdd);
        //int ans2 = max(evenOdd, oddEven);
        //cout << allEven << " " << allOdd << " " << evenOdd << " " << oddEven << endl;
        return max(ans1,cnt);
    }
};