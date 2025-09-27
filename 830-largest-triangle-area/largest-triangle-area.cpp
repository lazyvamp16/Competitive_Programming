class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points){
        double area = 0.0, ans=0.0;
        for(auto i: points){
            for(auto j: points){
                for(auto k: points){
                    if(i==j || i==k || j==k) continue;
                    double a = sqrt(pow((i[0]-j[0]),2) + pow((i[1]-j[1]),2));
                    double b = sqrt(pow((j[0]-k[0]),2) + pow((j[1]-k[1]),2));
                    double c = sqrt(pow((k[0]-i[0]),2) + pow((k[1]-i[1]),2));
                    if(a+b>c && b+c>a && a+c>b){
                        double s = (a+b+c)/2.0;
                        area = sqrt(s*(s-a)*(s-b)*(s-c));
                        ans = max(area,ans);
                    }
                }
            }
        }
        return ans;
    }
};