
//1423. Maximum Points You Can Obtain from Cards
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int j= n;
        int sum=0;
        int tsum=0;
        for(int i=0; i<n; i++) 
        {
            if(i<n-k) sum = sum + cardPoints[i];
            tsum = tsum + cardPoints[i];
        }
        int minsum = sum;
        for(int i=1; i<=k; i++) {
            sum = sum + cardPoints[i+n-k-1] - cardPoints[i-1];
            minsum = min(sum,minsum);
            }
        return(tsum-minsum);
        
    }
};
