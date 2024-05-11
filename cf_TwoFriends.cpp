// 1969 A

#include <iostream>
#include <vector>
using namespace std;

int main()
{
int t;
cin >> t;
while (t--)
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++) 
    {
        int x;
        cin>>x;
        v[i]=x;
    }
    int ans=3;
    if (n==2) ans=2;
    else
    {
        for(int i:v)
        {
            if(v[v[i]-1]==i+1) 
            {
                ans=2;
                break;
            }
        }
    }
    cout << ans <<endl;
}
}