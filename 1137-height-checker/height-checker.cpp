class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> og = heights;
        int cnt = 0;
        sort(heights.begin(),heights.end());
        for(int i=0; i<og.size(); i++){
            if(og[i]!=heights[i]) cnt++;
        }
        return cnt;
    }
};