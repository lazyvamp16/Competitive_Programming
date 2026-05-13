class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i : nums){
            int temp = i;
            vector<int> tans;
            while(temp>0){
                int digit = temp%10;
                temp/=10;
                tans.push_back(digit);
            }
            ans.insert(ans.end(),tans.rbegin(),tans.rend());
        }
        return ans;
    }
};