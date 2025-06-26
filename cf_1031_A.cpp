// Codeforces Round 1031 (Div. 2)
// Problem A

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
    int p;
    cin >> p;   
    while(p--){
        int total, req1, req2, t1 ,t2;
        cin >>total >> req1 >> req2 >> t1 >> t2;
        int cnt=0;
        if(t1<t2){
            if(total>=req1){
                cnt = ((total-req1)/t1)+1;
                total-= cnt*t1;
            }
            if(total>=req2){
                cnt+= ((total-req2)/t2)+1;
            }
            /*
            while(total>=req1){
                total-=t1;
                cnt++;
            }
            while(total>=req2){
                total-=t2;
                cnt++;
            }
            */
        }
        else{
            if(total>=req2){
                cnt = ((total-req2)/t2)+1;
                total-= cnt*t2;
            }
            if(total>=req1){
                cnt+= ((total-req1)/t1)+1;
            }
            /*
            while(total>=req2){
                total-=t2;
                cnt++;
            }
            while(total>=req1){
                total-=t1;
                cnt++;
            }
            */
        }
        cout << cnt << endl;
    }
}