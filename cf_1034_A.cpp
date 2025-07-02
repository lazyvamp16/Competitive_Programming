// Codeforces Round 1034 (Div. 3)
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
        int n;
        cin >> n;
        if(n<4) cout << "Alice" <<endl;
        else if(n%4==0) cout << "Bob" <<endl;
        else cout << "Alice" << endl;
    }
}

// 0 1 2 3 4 5 6 7 8 9 10 11 12