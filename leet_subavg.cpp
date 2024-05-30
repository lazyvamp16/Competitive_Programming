// 643. Maximum Average Subarray I
// sliding window
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum =0;
        for(int i=0; i<k;i++) sum = sum + nums[i];
        int maxsum = sum;
        for(int i=0; i<nums.size()-k;i++){
            sum = sum  + nums[k+i] - nums[i];
            maxsum = max(maxsum,sum);
        }
        return (double(maxsum) / double(k));
    }
};
