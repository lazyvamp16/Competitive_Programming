class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        char prev = num[0];
        int count =1, ans = -1;
        string result = "";
        for(int i=1; i<n; i++){
            if(num[i]==prev) {
                count++;
                if (count==3) ans = max(ans,(num[i] - '0'));
            }
            else {
                count =1;
                prev = num[i];
            }
        }
        if(ans==-1) return result;
        else {
            result = to_string(ans);
            result +=result+result;
        }
        return result;
    }
};