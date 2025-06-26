// Codeforces Round 1029 (Div. 3)
// Problem c

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;

//  2 6 5 4 3 1
//  2 3 4 5 6 1

// 1 2 3 4 5 6
// 2 5 4 3 6 1


int main()
{
    int p;
    cin >> p;   
    while(p--){
        int n;
        cin >>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i]; 
        }   
        int count = 1;
        unordered_set<int> s1,s2;
        s1.insert(arr[0]);
        for(int i=1;i<n;i++){
            if(s1.find(arr[i])!=s1.end()){
                s1.erase(arr[i]);
            }
            s2.insert(arr[i]);
            if(s1.empty()){
                count++;
                unordered_set<int> temp = s1;
                s1 = s2;
                s2 = temp;
            }
        }
        cout << count << endl;
    }
}