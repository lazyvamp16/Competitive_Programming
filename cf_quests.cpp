//Quests
// codeforces round 916 Div 3
// C

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t,n,k,x;
    cin >> t;
    while(t--)
    {
        vector<int> v1,v2;
        cin >> n >> k;
        for(int i=0; i<n;i++)
        {
            cin >> x;
            v1.push_back(x);
        }
        for(int i=0; i<n;i++)
        {
            cin >> x;
            v2.push_back(x);
        }
        int msum = 0;
        int sum = 0;
        int tsum =0;
        for(int i=0; i<n && i<k; i++)
        {   
            tsum = tsum + v1[i];
            sum = tsum + (k-i-1)*(*max_element(v2.begin(),v2.begin()+i+1));
            msum = max(msum,sum);
        }
        cout << msum << endl;
    }
}