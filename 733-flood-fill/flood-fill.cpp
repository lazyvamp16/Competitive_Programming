class Solution {
private:
    void dfs(vector<vector<int>>& image, int r, int c, int col, int og){
        image[r][c] = col;
        if((r+1)<image.size() && image[r+1][c]==og && image[r+1][c]!=col) 
        {
            dfs(image,r+1,c,col,og);
        }
        if((c-1)>=0 && image[r][c-1]==og && image[r][c-1]!=col) 
        {
            dfs(image,r,c-1,col,og);
        }
        if((r-1)>=0 && image[r-1][c]==og && image[r-1][c]!=col) 
        {
            dfs(image,r-1,c,col,og);
        }
        if((c+1)<image[0].size() && image[r][c+1]==og && image[r][c+1]!=col) 
        {
            dfs(image,r,c+1,col,og);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        dfs(image,sr,sc,newColor,originalColor);
        return image;
    }
};