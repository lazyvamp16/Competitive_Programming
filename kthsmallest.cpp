#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {7, 10, 4 ,3 ,20 ,15};
    int k=3;
    int n=6;

    priority_queue<int, vector<int>, greater<int>> pr;
    for(int i=0;i<n;i++) pr.push(arr[i]);

    for(int i=1;i<k;i++) pr.pop();
    cout << pr.top();
    //vector<int> ar;
    //for(int i=0;i<n;i++) ar.push_back(arr[i]);



    //int start = *max_element(ar.begin(),ar.end());



    // sort(ar.begin(),ar.end());
    // cout<<(ar[k-1]);
}