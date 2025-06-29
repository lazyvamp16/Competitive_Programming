class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int cnt = 0;
        int MOD = 1e9+7;
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        vector<int> power(j+1,1);
        for(int p=1; p<=j; ++p){
            power[p] = (power[p-1]*2) % MOD;
        }
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                //cnt = (cnt + ((long long)pow(2,(j-i)))%MOD)%MOD;
                //long long power = pow(2,(j-i));
                cnt = (cnt + power[j-i] % MOD) % MOD;
                i++;
            }
            else{
                j--;
            }
        }
        //int ans = cnt%MOD;
        return cnt;
    }
};