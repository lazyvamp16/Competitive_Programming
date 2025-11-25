class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long num =1;
        int cnt =1;
        while(cnt<1e6){
            num=num%k;
            if(num%k==0) return cnt;
            num = num*10 +1;
            cnt++;
        }
        return -1;
    }
};