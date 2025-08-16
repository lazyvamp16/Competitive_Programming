class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        /*
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(abs(abs(nums[j])-abs(nums[i])) <=min(abs(nums[i]),abs(nums[j]))) cnt++;
            }
        }
        */
        int j =0;
        for(int i=0; i<n; i++) nums[i]= abs(nums[i]);
        sort(nums.begin(),nums.end());
        /*
        for(int i=0; i<n; i++){
            //while (j < n && nums[j] <= 2 * nums[i]) j++;
            //cnt += (j - i - 1);
            for(; j<=n; j++){
                if(((j<n && nums[j]-nums[i])<=nums[i])) continue;    
                else{
                    cnt+=(j-i-1);
                    break;
                }
            }
        }
        */
        for (int i = 0; i < n; i++) {
            if (j < i + 1) j = i + 1;   // make sure j starts ahead of i
            for (; j < n; j++) {
                if (nums[j] - nums[i] <= nums[i]) continue;
                else break;
            }
            cnt += (j - i - 1); 
        }
        return cnt;
    }
};