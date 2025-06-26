// Codeforces Round 1029 (Div. 3)
// Problem B 

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

//  2 6 5 4 3 1
//  2 3 4 5 6 1

// 1 2 3 4 5 6
// 2 5 4 3 6 1


int main()
{
    int p;
    cin >> p;   
    while(p--){
        int n;
        cin >>n;
        for(int i=2;i<=n;i++){
            cout << i << " " ;
        }   
        cout << 1 << endl;
    }
}