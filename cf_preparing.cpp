//Preparing for the Contest
// codeforces round 916 Div 3
// B
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int t,n,k;
    cin >> t;
    while(t--)
    {
        cin >> n>> k;
        for(int i=1; i<=k; i++) cout << i << " ";
        for(int i=n;i>k;i--) cout << i << " ";
        cout << endl;
    }
}