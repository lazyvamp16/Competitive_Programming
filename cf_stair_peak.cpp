#include<iostream>
 
using namespace std;

//Stair, Peak, or Neither?
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (y>x && z>y) cout << "STAIR"<< endl;
        else if ( y>x && z<y) cout << "PEAK" << endl;
        else cout <<"NONE" << endl;
    }
}