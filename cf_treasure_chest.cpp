//treasure chest

#include<iostream>
#include<unordered_map>
 
using namespace std;

int main()
{
    
     int t;
     cin>>t;
     while(t--) 
    {
        int x,y,k;
        cin >> x >>y >>k;
        if(y<x) cout << x << endl;
        else
        {
            if (x+k >= y) cout << y << endl;
            else cout << 2*y - x -k << endl ;
        }   
    }
    return(0);
}
    