// Stone Age Problem
// 792 B

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main()
{
    int n,q,x,t,i;
    int sum=0;
    vector<int> v;
    cin >> n>> q;
    for(i=0; i<n; i++)
    {
        cin>>x;
        sum+=x;
        v.push_back(x);
    }
    for(int j=0; j<q; j++)
    {
        cin >> t;
        if(t==2) 
        {
            cin>> x;
            sum=n*x;
            for(auto& i:v) i=x;
        }
        else if(t==1)
        {
            cin>> i>> x;
            sum = sum + x - v[i-1];
            v[i-1] = x;
        }
        cout << sum << endl;
    }
}

    /*
    int n,q,x,t,i;
    cin >> n>> q;
    vector<int> v;
    for(int i =0; i< n; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    for(int j=0; j<q; j++)
    {
        cin >> t;
        if(t==2) 
        {
            cin>> x;
            for(auto& i:v) i=x;
        }
        else if(t==1)
        {
            cin>> i>> x;
            v[i-1] = x;
        }
        cout << accumulate(v.begin(),v.end(),0) << endl;
    }
    
}
*/
