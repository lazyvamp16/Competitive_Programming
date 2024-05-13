#include<iostream>
#include<vector>
#include<cmath>
 
using namespace std;

int main()
{
    
    int t;
    cin>>t;
    while(t--) 
    {
        int max=0;
        int p=1;
        int fans=10;
        int n,k,d;
        cin >> n >> k;
        for(int i=0;i<n;i++) 
        {
            int x;
            cin>>x;
            p=p*x;
            if(x%k==0 || p%k==0) fans=0;
            if ((x%k)> max) 
            {
                d=x/k;
                max=abs(x-d*k); 
            }
        }
        int ans=min((k-max),fans);
        if(k==4) cout<<min(ans,2)<<endl;
        else cout<<ans<<endl;
    }
}