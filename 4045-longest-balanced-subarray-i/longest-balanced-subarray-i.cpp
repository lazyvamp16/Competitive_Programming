class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            unordered_set<int> odd,even;
            int cnt =0;
            for(int j=i; j<n; j++){
                if(odd.count(nums[j]) || even.count(nums[j])) {
                    cnt++; 
                    if(even.size()==odd.size()){
                        int len = even.size()+odd.size()+cnt;
                        ans = max(ans,len);
                        if(ans==n) return ans;
                    } 
                    continue;
                }
                else if(nums[j]%2==0) even.insert(nums[j]);
                else odd.insert(nums[j]);
                if(even.size()==odd.size()){
                    int len = even.size()+odd.size()+cnt;
                    ans = max(ans,len);
                    if(ans==n) return ans;
                } 
            }
        }
        return ans;
    }
};