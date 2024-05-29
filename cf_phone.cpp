// Round 946 Div 3
// A - Phone Desktop

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t ;
    cin >> t;
    while(t--)
    {
    int x,y,nx,ny;
    cin >> x>>y;
    ny = (y+1)/2;
    if(y%2==0)
    {
        if(x>(ny*7)) nx = (x-(ny*7)+14)/15;
        else nx=0;
    }
    else if(x>((ny-1)*7+11)) nx = x-((ny-1)*7+25)/15;
    else nx =0;
    cout << ny + nx << endl;
    }
}