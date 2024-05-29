//// Round 946 Div 3
//B Symmetric Encoding

#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        int n;
        cin >> n >> s;
        string c=s;
        sort(c.begin(),c.end());
        for(int i=0; i<n;i++)
        {
            while(c[i]==c[i+1]) 
            {
                c.erase(i,1);  
                n--;
            }
        }
        string ans="";
        unordered_map<char,char> m;
        for (int i=0; i<n;i++) 
        {
            m[c[i]] = c[n-1-i];
        }
        for (char i:s) ans.push_back(m[i]);
        cout << ans<< endl;
    }
}
