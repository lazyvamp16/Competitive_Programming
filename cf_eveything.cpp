// We Got Everything Covered!
// round 921 Div 2 A
#include<bits/stdc++.h>
using namespace std;

int main()
{
int t;
cin>> t;
while(t--)
{
    int len,k;
    cin >> len >> k;
    string st;
    for(int i=int('a');i<int('a')+k;i++)
    {
        st.push_back(char(i));
    }
    for(int i=1; i<len; i++)
    {
        st.append(st);
    }
    cout << st<<endl;
}
}
