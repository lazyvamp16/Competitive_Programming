class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int,int> m;
    //int n1,n2;

    FindSumPairs(vector<int>& num1, vector<int>& num2) {
        nums1 = num1;
        nums2 = num2;
        //n1 = nums1.size();
        //n2 = nums2.size();
        for(int i:num2){
            m[i]++;
        }
    }
    
    void add(int index, int val) {
        m[nums2[index]]--;
        nums2[index]+=val;
        m[nums2[index]]++;
        
    }
    
    int count(int tot) {
        int cnt = 0;
        /*
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                if(nums1[i]+nums2[j] == tot) cnt++;
            }
        }
        */
        for(int i: nums1){
            if(m.find((tot-i))!=m.end()){
                cnt+=m[(tot-i)];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */