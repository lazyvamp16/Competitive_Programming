class Solution {
public:
    int totalMoney(int n) {
        int sum =0;
        int rem = n%7;
        int quo = n/7;
        for(int i=0; i<quo; i++){
            sum += 28+ 7*i;
        }
        cout << sum;
        int x = quo+1;
        for(int i=0; i<rem; i++){
            sum += x+i;
        }
        return sum;
    }

};