class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        int ans =-1;
        bool flag = false;
        for(int i:nums){
            if(i==1) {
                cnt++;
                flag=true;
            }
        }
        if(flag){
            ans = n-cnt;
        }
        else{
            ans=n;
            for(int j=0; j<n; j++){
                
                for(int i=0; i<n-1; i++){
                    int x= gcd(nums[i],nums[i+1]);
                    nums[i] = x;
                    if(x==1) {
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
                ans++;
            }
        }
        if(flag) return ans;
        else return -1;
    }
};