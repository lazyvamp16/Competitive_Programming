class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n =nums.size();
        vector<int> neww;
        if(n==1) return nums[0];
        for(int i=0; i<n-1; i++){
            int temp = nums[i];
            vector<int> neww;
            for(int j=1; j<n-i; j++){
                //temp = nums[j];
                neww.push_back((nums[j]+nums[j-1])%10);
            }
            nums = neww;
            //for (int x:nums) cout << x << " ";
            //cout << endl;
        }
        //for (int i:nums) cout << i << " ";
        return nums.back();
    }
};