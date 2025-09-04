#include <iostream>
#include <vector>
#include <map>
#include <queue> 
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;

int nx[]= {-1,-1,0,1,0};
int ny[]= {-1,0,1,0,-1};
unordered_map<int,char> dir_map;


void print(int x, int y, int z, int sx, int sy, vector<vector<int>>& vis){
    cout << "YES" <<endl << z << endl;
    // NOT while(x!=sx && y!=sy
    while(!(x==sx && y==sy) && z!=0){
        int i = vis[x][y];
        cout << dir_map[i];
        x-=nx[i];
        y-=ny[i];
    }
    cout <<endl;
    return;
}

int main() {
    int n,m;
    cin >> n>>m;
    vector<vector<int>> mat(n,vector<int>(m,0));
    vector<pair<int,int>> start;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char x;
            cin >> x;
            // 0 if x=='#'
            if(x=='.') {
                mat[i][j]=1;
                if(i==n-1 || i==0 || j==m-1 || j==0) start.push_back({i,j});
            }
            else if(x=='A') mat[i][j]=2;
            else if(x=='M') mat[i][j] =-1; 
        }
    }
    // int nx[]= {-1,-1,0,1,0};
    // int ny[]= {-1,0,1,0,-1};
    dir_map[1]='D'; // X coordinate is moving in y direction
    dir_map[2]='L';
    dir_map[3]='U';
    dir_map[4]='R';
    queue<vector<int>> q;
    if(start.empty()) {
        vector<vector<int>> v;
        print(0,0,0,0,0,v);
        return 0;
    }
    for(auto s: start){
        int sx = s.first;
        int sy = s.second;
        q.push({sx,sy,0});
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[sx][sy]=5;
        while(!q.empty()){
            int x = q.front()[0];
            int y = q.front()[1];
            int z = q.front()[2];
            q.pop();
            if(mat[x][y]==-1){
                break;
            }
            else if(mat[x][y]==2) {
                print(x,y,z,sx,sy,vis);
                return 0;
            }
            for(int i=1; i<=4; i++){
                int ni = x+nx[i];
                int nj = y+ny[i];
                //CHECK BOUNDS FIRST
                if(ni>=0 && ni<n && nj>=0 && nj<m && mat[ni][nj] && vis[ni][nj]==0){
                    vis[ni][nj]=i;
                    q.push({ni,nj,z+1});
                }
            }
        }
    }
    cout << "NO";
    return 0;
}