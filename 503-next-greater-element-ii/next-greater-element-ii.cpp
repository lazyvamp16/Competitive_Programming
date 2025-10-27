class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        for(int i=0; i<n; i++){
            nums.push_back(nums[i]);
        }
        vector<int> ans(n,-1);

        for(int i=2*n-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(!st.empty()) ans[i%n]=st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};