// Codeforces Round 1028 (Div. 2)
// Problem A

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int a,b,c,d;
        cin >> a >> c >> b >> d;
        int w1 = min(a,b);
        int w2 = min(c, d);
        if(w1 >= w2) cout << "Gellyfish" << endl;
        else cout << "Flower" << endl;
    }
}