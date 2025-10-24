class Solution {
public:
    int nextBeautifulNumber(int n) {
        for(int i=n+1; i<=1e6; i++ ){
            vector<int> m(10);
            int temp = i;
            while(temp>0){
                int digit = temp%10;
                m[digit]++;
                temp/=10;
            }
            bool flag = true;
            for(int i=0; i<10; i++){
                if(m[i]>0 && m[i]!=i) flag = false;
            }
            // for(auto i:m){
            //     if(i.second!=i.first) flag = false;
            // }
            if(flag){
                return i;
            }
        }
        return 1224444;
    }
};