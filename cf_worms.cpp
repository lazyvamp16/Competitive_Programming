// Worms
//Round 271 div 2
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,x,r;
    int sum=0;
    vector<int> v1, v2;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        sum = sum +x;
        v1.push_back(sum);
    }
    cin >> r;
    for(int i=0; i<r; i++)
    {
        cin>> x;
        v2.push_back(x);
    }

    for(int i=0; i<r; i++)
    {
        int target = v2[i];
        int start = 0; 
        int end = n-1;
        while(start<end)
        {
            int mid = start + (end-start) / 2;
            if (v1[mid]>target) end = mid;
            else start = mid+1; 
        }
        cout << start + 1 << endl;
    }    
}