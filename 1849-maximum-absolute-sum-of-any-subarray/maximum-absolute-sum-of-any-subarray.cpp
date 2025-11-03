class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mxp=0;
        int mxn=0;
        int currp=0;
        int currn=0;
        for(int i=0; i<nums.size(); i++){
            currp += nums[i];
            mxp = max(currp,mxp);
            if(currp<0) currp=0;
            currn-=nums[i];
            if(currn<0) currn =0;
            mxn = max(currn,mxn);
        }
        return max(mxp,mxn);
    }
};