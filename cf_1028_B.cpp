// Codeforces Round 1028 (Div. 2)
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
    cin >> t;
    while(t--){
        int n,x,y;
        cin >> n;
        vector<int> v1,v2,v3;
        for(int i=0; i< n; i++){
            cin >> x;
            v1.push_back(x);
        }
        for(int i=0; i< n; i++){
            cin >> x;
            v2.push_back(x);
        }

        int p1,p2;
        int m1=0;
        int m2=0;
        for(int i=0; i< n; i++){
            int ans=0;
            if(i==0){
                v3.push_back(pow(2,v1[i])+pow(2,v2[i]));
                m1=0;
                m2=0;
                continue;
            }

            if(v1[m1]< v1[i]){
                m1 = i;
            }
            if(v2[m2]< v2[i]){
                m2 = i;
            }
            
            if(v1[m1] > v2[m2]){
                ans = pow(2, v1[m1])+ pow(2, v2[i-m1]);
            } else if (v1[m1] < v2[m2]){
                ans = pow(2, v2[m2])+ pow(2, v1[i-m2]);
            } else if (v1[i-m1] > v2[i-m2]){
                ans = pow(2, v2[m2])+ pow(2, v1[i-m2]);
            } else{
                ans = pow(2, v1[m1])+ pow(2, v2[i-m1]);
            }
            v3.push_back(ans);
        }
        for(int i=0; i< n; i++){
            cout << v3[i] << " ";
        }
        cout <<endl;
    }
}