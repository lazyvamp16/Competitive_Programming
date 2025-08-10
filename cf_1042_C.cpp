// Codeforces Round 1042 (Div. 3)
// Problem C

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,k,x;
        cin >>n>>k;
        bool ans = true;
        unordered_map<int, int> m;

        for(int i=0; i<n; i++){
            cin >> x;
            m[x % k]++;    
        }

        for(int i=0; i<n; i++){
            cin >> x;
            int r = x % k;
            int alt = (k -r) % k; 

            if(m.find(r) != m.end()){ 
                m[r]--;
                if(m[r] == 0) m.erase(r);
            }
            else if(m.find(alt) != m.end()){ 
                m[alt]--;
                if(m[alt] ==0) m.erase(alt);
            }
            else {
                ans = false;
            }
        }

        if (ans) cout << "YES\n";
        else cout <<"NO\n";
    }
    return 0;
}
