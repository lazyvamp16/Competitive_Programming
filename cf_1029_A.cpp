// Codeforces Round 1029 (Div. 3)
// Problem A

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int p;
    cin >> p;   
    while(p--){
    int n,t;
    cin >>n>>t;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }   
    int s = n;
    int e = 0;
    for(int i=0;i<n;i++){
        if(v[i]==1) {
            s=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(v[i]==1) {
            e=i;
            break;
        }
    }
    //cout << s << " " << e << endl;
    if((e-s)>=t) cout << "NO" <<endl;
    else cout << "YES"<<endl;
    }

}