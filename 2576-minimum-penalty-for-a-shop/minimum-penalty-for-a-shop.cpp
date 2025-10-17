class Solution {
public:

    int bestClosingTime(string cus) {
        int ans = 0;
        int cnt= 0;
        int el =0;
        for(int i=0; i<cus.size(); i++){
            char c = cus[i];
            if(c=='Y') {
                cnt++;
                if(cnt > ans){
                    ans = cnt;
                    el = i+1;
                }
            }
            else cnt--;
        }
        return el;
    }
    
};