class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> m;
        int num ;
        for(int i :nums){
            if(i<0) {
                num = abs(i%value);
                num = value-num;
                m[num%value]++;
            }
            else {
                num = i%value;
                m[num]++;
            }
            cout <<num<< " ";
        }
        int mn = 1e6;
        int element =0;
        for(int i=0; i<value; i++){
            if(!m.count(i)) return i;
            else if(m[i]<mn){
                mn = m[i];
                element = i;
            }
        }
        int ans = element + mn*value;
        return ans;
    }
};