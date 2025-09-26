class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int l=0; l<nums.size();l++){
            for(int r=nums.size()-1; r>0; r--){
                if(l+1<r){
                    auto it= lower_bound(nums.begin()+l+1, nums.begin()+r, (nums[r]-nums[l]+1));
                    if(it!=nums.begin()+r) {
                        //cout << l << r << (r-(distance(nums.begin(), it)))<<endl;
                        count += r-(distance(nums.begin(), it));
                    }
                }
            }
        }
        return count;
    }
};