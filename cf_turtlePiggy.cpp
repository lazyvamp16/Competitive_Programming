// Codeforces Round 949 (Div. 2)
//A. Turtle and Piggy Are Playing a Game

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int count(int x){
    int c=0;
    int i=2;
    int n = x/2;
    while(i<=n && x!=1)
    {
        if(x%i==0)
        {   
            x=x/i;
            c++;
        }
        else i++;
    }
    return max(1,c);
}
int main(){
    int l,r;
    int ans=1;
    cin>> l >> r;
    
    while (pow(2,ans)<=r){
        ans++;
    }
    /*
    if(r%2==1) r--;
    for(int i=r;i>=1000000;i-=2){
        int c = count(i);
       //if(c<ans && d<ans) break;
        if(c>10) cout << i<< ":" << count(i)<<endl;
    }
    */
    cout<<--ans<<endl;
}