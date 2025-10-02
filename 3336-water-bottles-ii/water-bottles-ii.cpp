class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        int e =0;
        while(numBottles>0){

            ans+=numBottles;
            e += numBottles;
            numBottles=0;
            while(e>=numExchange) {
                e-=numExchange;
                numBottles++;
                numExchange++;
            }
        }
        return ans;
    }
};