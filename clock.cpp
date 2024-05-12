#include<iostream>
 using namespace std;

//Clock Conversion
int main()
{
int t;
cin >>t;
while (t--){
    string c;
    cin >> c;
    string h="";
    string m="";

    h=h+c[0] + c[1];
    m=m+c[3] + c[4];

    int hr = stoi(h);

    if (hr>12)
    {
        hr = hr-12;
        if(hr<10) cout << "0" << to_string(hr) << ":" << m << " " << "PM"<<endl; 
        else cout << to_string(hr) << ":" << m << " " << "PM"<<endl; 
    }   
    else if ( hr==12) cout << c << " " << "PM"<<endl;
    else if (hr==0) cout << "12" << ":" << m << " " << "AM"<<endl;
    else cout <<c << " " << "AM"<<endl;
}
}