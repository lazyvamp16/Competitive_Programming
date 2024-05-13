#include<iostream>
#include<cmath>
 using namespace std;

//0, 1, 2, Tree!
int main()
{
int t;    
cin>> t;
while (t--)
{
    int a,b,c;
    cin>>a>>b>>c;
    if(c!=a+1) cout << -1 << endl;
    else
    {
    if(a==0) cout << b << endl;
    else
    {
    int dep = log2(a);
    int ans;
    int left = max(0,((dep+1)*(dep+1)) -a - 1);
    if(b>=left) b=b-left;
    int r = b/(a+1);
    if(b==0) ans = dep + r + 1 ;
    else ans = dep + r +2;
    cout << ans<< endl;
    }
    }
}
}

