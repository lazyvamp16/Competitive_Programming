// Codeforces Round 1032 (Div. 3)
// Problem C

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int r,c,x;
        int mx=-1;
        int cnt=0;
        cin >> r >> c;
        vector<bool> row(r, false);
        vector<bool> col(c,false);
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >>x;
                if (x>mx) {
                    mx=x;
                    fill(row.begin(), row.end(),false);
                    fill(col.begin(), col.end(), false);
                    row[i]=true;
                    col[j]=true;
                }
                else if (mx==x) {
                    row[i]=true;
                    col[j]=true;
                }
            }
        }
        int nr=0,nc=0;
        for(bool b:row) if(b) nr++;
        for(bool b:col) if(b) nc++ ;
        if(nr>1 || nc>1){
            cout<<mx << endl;
        }
        else cout << (mx-1) << endl;
    }
}

