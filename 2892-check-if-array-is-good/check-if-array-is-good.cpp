class Solution {
public:
    vector<int> createBase(int x){
        vector<int> v(x,x-1);

        for(int i=0; i<x-1; i++){
            v[i]=i+1;
        }
        return v;
    }
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        v = createBase(n);
        //for(int i: v) cout << i << " ";
        sort(nums.begin(),nums.end());
        if(nums==v) return true;
        return false;
    }
};