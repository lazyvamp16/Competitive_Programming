class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            ans.push_back(nums[i]);
            while(ans.size()>1){
                long long b = ans[ans.size() - 2];
                if(gcd(b,ans.back())==1) break;
                else{
                    long long lcm = 1LL* b*ans.back()/gcd(b,ans.back());
                    ans.pop_back();
                    ans.pop_back();
                    ans.push_back(lcm);
                }
            }
        }
        return ans;
    }
};