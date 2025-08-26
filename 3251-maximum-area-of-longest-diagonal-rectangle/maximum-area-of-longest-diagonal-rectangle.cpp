class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxd = -1, area=-1, d_sq;
        for(auto i : dimensions){
            int l = i[0];
            int b = i[1];
            d_sq = l*l + b*b;
            if(d_sq>maxd) {
                maxd = d_sq;
                area = l*b;
                //cout << d_sq << " " << area << endl;
            }
            else if(d_sq==maxd){
                area = max(area,l*b);
            }
        }   
        return area;     
    }
};