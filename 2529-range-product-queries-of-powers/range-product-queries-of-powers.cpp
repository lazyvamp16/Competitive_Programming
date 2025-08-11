class Solution {
public:
    int powerof2(int n){
        for(int i=n; i>1; i--){
            if((i & (i-1))==0) return i;
        }
        return 1;
    }

    vector<int> f(int n){
        vector<int> powers;
        int power = 1;
        while (n > 0) {
            if (n%2 != 0) { // if last bit is 1
                powers.push_back(power);
            }
            power*=2; // next power of 2
            n/=2;     // check next bit
        }
        return powers;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers,ans;
        int MOD = 1e9+7;
        powers = f(n);
        reverse(powers.begin(),powers.end());
        // while (true){
        //     int p = powerof2(n);
        //     powers.push_back(p);
        //     n = n - p;
        //     if(n<=0) break;
        // }
        int s = powers.size();
        for(int i=0; i<queries.size(); i++){
            int start = queries[i][0];
            long long prod =1;
            int end = queries[i][1];
            for(int j = s-1-start; j>=s-1-end; j--){
                prod = (((powers[j]%MOD)*(prod)%MOD) % MOD);
            }
            ans.push_back(prod);
        }
        return ans;
    }
};