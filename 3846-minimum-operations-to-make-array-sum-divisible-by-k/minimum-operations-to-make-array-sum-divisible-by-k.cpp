class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        for(int i=sum; i>=0; i--){
            //cout << i << " ";
            if(i%k==0) return (sum-i);
        }
        return 0;
    }
};