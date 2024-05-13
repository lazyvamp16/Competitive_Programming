#include<iostream>
#include<vector>
using namespace std;

//BMAIL Computer network
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i =0; i<n-1; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    vector<int> ans;
    ans.push_back(n);
    int index = n-2;
    int r = v[index];
    ans.push_back(r);

    while (r>1)
    {
        index = r-2;
        r = v[index];
        ans.push_back(r);
    }
    
    for(int i=ans.size()-1; i>=0; i--) cout << ans[i] << " ";
}

