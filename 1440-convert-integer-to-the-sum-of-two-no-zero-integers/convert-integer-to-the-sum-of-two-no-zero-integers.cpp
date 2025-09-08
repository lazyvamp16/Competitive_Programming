class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<n; i++){
            if(i>1 && i%10==0) continue;
            bool ans = true;
            int temp = n-i;
            while(temp>0){
                if(temp%10==0) {
                    ans=false;
                    break;
                }
                temp/=10;
            }
            if(ans){
                int temp2=i;
                while(temp2>0){
                    if(temp2%10==0) {
                        ans=false;
                        break;
                    }
                    temp2/=10;
                }
            }
            if(ans) return {i,n-i};
        }
        return {-1};
    }
};