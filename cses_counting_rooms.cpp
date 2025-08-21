#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int j, int n, int m,
          vector<vector<int>>&vis, vector<vector<int>>&matrix){
    vis[i][j]=1;
    for(int x=-1; x<=+1; x++){
      for(int y=-1; y<=+1; y++){
        if(x==0 || y==0){
          int ni = i+x;
          int nj = j+y;
          if (ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] == 1 && !vis[ni][nj]) {
            dfs(ni,nj,n,m,vis,matrix);
          }
        }
      }
    }
  }

int main() {
    int n,m;
    cin >> n>> m;
    char x;
    vector<vector<int>> matrix(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin >> x;
        if(x=='.') matrix[i][j] = 1;
      }
    }
    
    // for(int i=0; i<n; i++){
    //   for(int j=0; j<m; j++){
    //     cout << matrix[i][j];
    //   }
    //   cout << endl;
    // }
    
    vector<vector<int>> vis(n,vector<int>(m,0));
    int cnt =0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(matrix[i][j] && !vis[i][j]) {
          cnt++;
          dfs(i,j,n,m,vis,matrix);
        }
      }
    }
    cout << cnt << endl;
  }