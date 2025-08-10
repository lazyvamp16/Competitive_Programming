// Codeforces Round 1042 (Div. 3)
// Problem B

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        if(n==2) {
            cout << -1 << " " << 2 << endl;
        }
        else{
            //vector<int> a(n);
            for(int i=0; i<n-1; i++){
                if(i%2==0) cout << -1 << " ";
                else cout << 3 << " ";
            }
            if((n-1)%2==0) cout << -1 << endl;
            else cout << 2 << endl;
        }
    }
    return 0;
}