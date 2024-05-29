// reducing Dishes

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int maxsum=0;
        for(int i=0;i<satisfaction.size();i++){
            int sum=0;
            int k=1;
            for(int j=i; j<satisfaction.size();j++){
                sum = sum + (k++)*satisfaction[j];
            }
            maxsum = max(maxsum,sum);
        }
        return(maxsum);
    }
};
