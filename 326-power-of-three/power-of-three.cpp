class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return false;
        long p = 1;
        while(p<=n){
            if(p==n) return true;
            p*=3;
        }
        return false;
    }
};