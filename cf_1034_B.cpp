// Codeforces Round 1034 (Div. 3)
// Problem B

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >>t;
    while(t--){
        int n,j,k,x,el;
        cin>>n >> j>> k;
        int mx=0;
        //vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>x;
            if(x>mx)mx=x;
            if(i==(j-1)) el=x;
        }
        if(k==1 && el!=mx) cout << "NO" <<endl;
        else cout << "YES" << endl;
    }
}
