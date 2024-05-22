// codeforces round 916 Div 3
// A
//Problemsolving Log
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{

    int t,n,c;
    string x;
    cin >> t;
    while (t--)
    {
        cin >> n >>x;
        unordered_map<char,int> m;
        c=0;
        for (int i=0; i<n; i++)
        {
            m[x[i]]++;
        } 
        for(int i=0; i<26; i++)
        {
            if(m[char(i+'A')]>=(i+1)) c++;
        }
        cout << c << endl;
    }
}