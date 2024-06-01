// B. Maximum Sum
// Codeforces Round 936 (Div. 2)
#include<bits/stdc++.h>
using namespace std;


int main(){
    //int t;
    //cin >> t;
    //while(t--){
    int MOD = 1e9 + 7;
    int n,k;
    int sum=0,tsum=0,msum=0;
    //vector<int> v;
    cin >>n >>k;
    for(int i=0; i<n;i++){
        int x;
        cin >> x;
        //v.push_back(x);
        sum = sum + x;
        tsum = (tsum + x)%MOD;
        msum = max(msum,sum);
        if(sum<0) sum=0;
    }
    tsum = tsum + msum;
    for(int i=1; i<k; i++){
        msum = msum + msum;
        tsum = tsum + msum;
    }
    //tsum = (k) * (tsum + msum);
    cout << (tsum%(MOD)) << endl;
//    }   
}
