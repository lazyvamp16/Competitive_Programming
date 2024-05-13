#include<iostream>
#include<unordered_map>
 
using namespace std;

//
int main()
{
    
     int t;
     cin>>t;
     while(t--)
    {
        unordered_map<int,int> m;
        int n,c;
        int sum=0;
        cin >> n >> c;
        for (int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            if(m.find(x)==m.end()) m[x]=1;
            else m[x]++;
        }
        for (auto i:m)
        {
            if(i.second > c)
            {
                sum+=c;
            }
            else sum+=i.second;
        }
        cout << sum << endl<<endl;
    }

    return 0;
}