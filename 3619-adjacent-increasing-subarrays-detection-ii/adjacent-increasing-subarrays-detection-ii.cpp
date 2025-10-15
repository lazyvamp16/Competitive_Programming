class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n= nums.size();
        int cnt =0;
        //if(n==2) return true;
        for(int i=0, j=i+k; j<n-1; i++,j++){
            //cout << cnt;
            if(cnt==k-1) return true;
            if(nums[i+1]<=nums[i] ) cnt = 0;
            else if(nums[j+1]<=nums[j]) cnt =0;
            else cnt++;
        }
        if (cnt==k-1) return true;
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int l= 1;
        int r= nums.size()/2;
        int mid,ans;
        while(l<=r){
            mid = (l + r)/2;
            if(hasIncreasingSubarrays(nums,mid)){
                l = mid + 1;
                ans = mid;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};