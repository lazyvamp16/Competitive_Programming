class Solution {
public:
    long long flowerGame(int n, int m) {
        int n_odd = n/2;
        if(n%2==1) n_odd+=1;
        int m_odd = m/2;
        if(m%2==1) m_odd+=1;

        int n_even = n-n_odd;
        int m_even = m-m_odd;
        
        //wrong because long long has space in it:
        //long long ans = long long(n_odd*m_even) + long long(n_even*m_odd); 

        //Recommended method:
        //long long ans = static_cast<long long>(n_odd) * m_even
        //                + static_cast<long long>(n_even) * m_odd;

        //Cleaner:
        // 1    type: int
        // 1L   type: long
        // 1LL  type: long long
        long long ans = 1LL*n_odd*m_even + 1LL*n_even*m_odd;
        
        return ans;
    }
};