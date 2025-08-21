#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    cin >> n>> m;
    vector<int> start(3,0),end(3,0);
    vector<vector<int>> matrix(n,vector<int>(m,1));
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        char x;
        cin >> x;
        if(x=='#') matrix[i][j] = 0;
        else if(x=='A') start= {i,j,0}; 
        else if(x=='B') end = {i,j,0}; //IMPORTANT TO MARK END AS ! IN MATRIX
        }
    }
    vector<vector<int>> path(n,vector<int>(m)); 
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<int> r{-1,0,1,0};
    vector<int> c{0,1,0,-1};
    queue <vector<int>> q;
    int x,y,d;
    bool ans = false; //IMPORTANT
    q.push(start);
    while(!q.empty()){
        x = q.front()[0];
        y = q.front()[1];
        d = q.front()[2];
        q.pop();
        if(x==end[0] && y==end[1]) {
            cout << "YES" << endl << d<<endl;
            ans = true;
            break;
        }
        //vis[x][y]=1;
        for(int i=0;i<4;i++){
            int nx = x + r[i];
            int ny = y + c[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] && !vis[nx][ny]){
                q.push({nx,ny,d+1});
                vis[nx][ny]=1; //IMPORTANT
                path[nx][ny] = i;
            }
        }
    }
    if(ans)
    {
        string s;
        int starti = end[0];
        int startj = end[1];
        for(int i=0; i<d; i++){
            if(path[starti][startj]==0){
                s+='U';
                starti++;
            }
            else if(path[starti][startj]==1){
                s+='R';
                startj--;
            }
            else if(path[starti][startj]==2){
                s+='D';
                starti--;
            }
            else {
                s+='L';
                startj++;
            }
        }
        reverse(s.begin(),s.end());
        cout << s;
    }
    else cout << "NO" <<endl;
}