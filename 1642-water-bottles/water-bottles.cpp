class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
        int ans = numBottles;
        while(sum>=numExchange){
            //sum = log(numBottles)/log(numExchange);
            int rem = sum%numExchange;
            sum/=numExchange;
            ans+=sum;
            sum+=rem;
        }
        return ans;
    }
};