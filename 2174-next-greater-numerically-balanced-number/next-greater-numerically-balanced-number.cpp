class Solution {
public:
    int nextBeautifulNumber(int n) {
        for(int i=n+1; i<=1e6; i++ ){
            unordered_map<int,int> m;
            int temp = i;
            while(temp>0){
                int digit = temp%10;
                m[digit]++;
                temp/=10;
            }
            bool flag = true;
            for(auto i:m){
                if(i.second!=i.first) flag = false;
            }
            if(flag){
                return i;
            }
        }
        return 1224444;
    }
};