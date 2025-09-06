/*
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        vector<long long> dp(16);
        long long num = 1;
        long long x = 4;
        for(int i=1; i<16; i++){
            dp[i]=x;
            x*=4;
        }
        //for(int i=1; i<10; i++) cout << dp[i] << " ";

        long long ans =0;
        
        for(auto query:queries){
            long long cnt=0;
            for(int i=query[0]; i<=query[1]; i++){
                // int temp = i;
                // while(temp >0){
                //     cnt++;
                //     temp/=4;
                // }
                // for(int j=1; j<16; j++){
                //     if(i<dp[j]) {
                //         cnt+=j;
                //         //cout << i<< " " << j << " " << dp[j];
                //         break;
                //     }
                // }
                int j = (int)(log(i) / log(4)) + 1;
                cnt += j;
            }
            ans += (cnt+1)/2;
        }
        
        return ans;
    }
};
*/
class Solution {
public:
    long long prefix(long long x) {
        if (x <= 0) return 0;
        long long sum = 0;
        long long base = 1;
        int step = 1;
        while (true) {
            long long left = base;
            long long right = base * 4 - 1;
            if (x < left) break;
            long long take = min(x, right) - left + 1;
            sum += take * step;
            base *= 4;
            step++;
        }
        return sum;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto& q : queries) {
            long long l = q[0], r = q[1];
            long long cnt = prefix(r) - prefix(l - 1);
            ans += (cnt + 1) / 2;
        }
        return ans;
    }
};
