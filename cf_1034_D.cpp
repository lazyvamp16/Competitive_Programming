// Codeforces Round 1034 (Div. 3)
// Problem D

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
        int n,k;
        string s;
        cin >> n >> k;
        cin >>s;
        int ones = 0;
        for (char c : s) {
            if (c == '1') {
                ones++;
            }
        }
        if (ones == 0) {
            cout << "Alice" << endl;
        }
        if(k>=ones) cout << "Alice" << endl;
        else if (2 * k >= n) {
        cout << "Alice" << std::endl;
        } 
        else{
        cout << "Bob" << std::endl;
        }
    }
}
