class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        vector<int> pairs;
        sort(potions.begin(),potions.end());
        for(int i:spells){
            int cnt=0;
            double find = (double(success)/i);
            auto it1 = lower_bound(potions.begin(),potions.end(),find);
            //auto it2 = upper_bound(potions.begin(),potions.end(),find);
            if(it1==potions.end()) pairs.push_back(0);
            else {
                int dist = distance(potions.begin(),it1);
                pairs.push_back(n-dist);
            }
        }
        return pairs;
    }
};