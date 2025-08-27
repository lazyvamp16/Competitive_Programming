// Codeforces Round 1044 (Div. 2)
// Problem B

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <map>
#include<numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int>len(n+1);
        for (int i =1; i<=n; i++) {
            cout << "? "<< i <<" "<< n;
            for (int j =1; j<=n; j++) cout <<" " << j;
            cout<<endl;
            cout.flush();
            int ans; 
            cin >>ans;
            if (ans ==-1) return 0; 
            len[i] = ans;
        }

        vector<int> order(n);
        iota(order.begin(), order.end(), 1);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return len[a]>len[b];
        });

        vector<int> path;
        int curr = order[0];
        path.push_back(curr);

        for (int targetLen = len[curr] - 1; targetLen >= 1; targetLen--){
            for (int v : order){
                if (len[v] != targetLen) continue;
                cout << "? " << curr << " 2 "<< curr<< " " << v << endl;
                cout.flush();

                int ans; 
                cin >>ans;
                if (ans == -1) return 0;
                if (ans==2){
                    path.push_back(v);
                    curr = v;
                    break;
                }
            }
        }
        cout << "! " <<path.size();
        for (int v:path) cout << " " <<v;
        cout <<endl;
        cout.flush();
    }
    return 0;
}
