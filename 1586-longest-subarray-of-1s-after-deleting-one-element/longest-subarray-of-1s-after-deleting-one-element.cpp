class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n+2);
        if(nums[0]==1) count[1]=1;
        bool flag=false;
        for(int k=1; k<n; k++){
            if(nums[k]==1) count[k+1] = count[k]+1;
            else flag=true;
        }
        int ans =0;
        int i=1,j=1;
        if(!flag) return nums.size()-1;
        //for(int i: count) cout << i << " ";
        //cout << endl;
        for(; i<n+2; i++){
            if(count[i]==0) {
                for(j=i+1; j<n+2; j++){
                    if(count[j]==0){
                        //cout << i << " " << j <<endl;
                        ans = max(ans,count[i-1] + count[j-1]);
                        i=j-1;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};