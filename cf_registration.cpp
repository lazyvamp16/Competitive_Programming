// Registration system

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map <string,int> m;
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        string x;
        cin >> x;
        auto it = m.find(x);
        if (it != m.end()){
            cout << (it->first + "1") << endl;;
        }
        else {
             m[x]++;
             cout<< "OK" << endl;
        }
    }
}