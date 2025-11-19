class Solution {
public:
    int findFinalValue(vector<int>& nums, int og) {
        unordered_set<int> s(nums.begin(),nums.end());
        while(s.count(og)){
            og<<=1;
        }
        return og;
    }
};