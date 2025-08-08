class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> ans(n,0);
        int i =0;
        int curr = 1;
        while(candies>0){
            //cout << i << " ";
            if(candies>=curr) ans[i%n]+=curr;
            else ans[i%n]+=candies;
            candies-=curr;
            curr++;
            i++;
        }
        return ans;
    }
};