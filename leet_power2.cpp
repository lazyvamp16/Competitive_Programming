// Power of Two
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return false;
        while(n!=1)
        {
            if(2*(int(n/2)) ==n) n=n/2;
            else return false;
        }
        return true;
    }
};
