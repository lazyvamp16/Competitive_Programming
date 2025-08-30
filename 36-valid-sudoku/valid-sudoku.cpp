class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n =3; // 3x3
        for(int i=0; i<n*n; i++){
            unordered_set<char> row,col;
            for(int j=0; j<n*n; j++){
                if(board[i][j]!='.'){
                    if(row.count(board[i][j])==1) {
                        //cout << " row";
                        return false;
                    }
                    row.insert(board[i][j]);
                }
                if(board[j][i]!='.'){
                    if(col.count(board[j][i])==1) {
                        //cout << " col " << board[j][i];
                        return false;
                    }
                    col.insert(board[j][i]);
                }
            }
        }
        for(int k=0; k<n; k++){
            for(int l=0; l<n; l++){
                unordered_set<char> sqr;
                for(int i = k*n; i<(k+1)*n; i++){
                    for(int j=l*n; j<(l+1)*n; j++){
                        if(board[i][j]=='.') continue;
                        if(sqr.count(board[i][j])==1) {
                            //cout << " sqr";
                            return false;
                        }
                        sqr.insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};