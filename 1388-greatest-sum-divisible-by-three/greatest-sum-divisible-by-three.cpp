class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        priority_queue<int> pq1, pq2;
        for(int i:nums){
            if(i%3==1) {
                pq1.push(i);
                if(pq1.size()>2) pq1.pop();
            }
            if(i%3==2) {
                pq2.push(i);
                if(pq2.size()>2) pq2.pop();
            }                
        }
        int one_1=1e9;
        int one_2=1e9;
        int two_1=1e9;
        int two_2=1e9;
        if(!pq1.empty()) {
            one_2 = pq1.top();
            pq1.pop();
        }
        if(!pq1.empty()) {
            one_1 = pq1.top();
            pq1.pop();
        }
        if(!pq2.empty()) {
            two_2 = pq2.top();
            pq2.pop();
        }
        if(!pq2.empty()) {
            two_1 = pq2.top();
            pq2.pop();
        }


        if(sum%3==0) return sum;
        if(sum%3==1) {
            int ans1 = sum - min(one_1,one_2);
            int ans2 = sum - two_1 - two_2;
            return max(ans1,ans2);
        }
        int ans3 = sum - min(two_1,two_2);
        int ans4 = sum - one_1 - one_2;
        return max(ans3,ans4);
    }
};