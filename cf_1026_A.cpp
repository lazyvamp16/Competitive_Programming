// Codeforces Round 1026 (Div. 2)
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
        vector<int> v;
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            v.push_back(x);
        }   
        int mx = 0;
        int mn = 0;
        int ans = 0;  // Initialize ans to avoid undefined behavior
        mn = *min_element(v.begin(), v.end());
        mx = *max_element(v.begin(), v.end());
        
        if(n < 2) {
            ans = 0;
        }
        else if((mx+mn) % 2 == 0) {
            ans = 0;
        }
        else if((mx+mn) % 2 == 1 && n == 2) {
            ans = 1;  // Consistent use of ans variable
        }
        else {
            sort(v.begin(), v.end());
            ans = n;  // Initialize to worst case
            for(int i=1; i<n; i++){
                if((v[i]+mn) % 2 == 1){
                    ans = i;
                    break;
                }
            }
            
            int cnt = 0;
            for(int i=n-2; i>=0; i--){  // Changed i>0 to i>=0 to check all elements
                cnt++;
                if((v[i]+mx) % 2 == 1){
                    ans = min(ans, cnt);
                    break;
                }
            }
        }
        cout << ans<<endl;
    }

}