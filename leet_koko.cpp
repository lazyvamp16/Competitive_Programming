//  Koko Eating Bananas
#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v {30,11,23,4,20};
    int h=6;
    int ans;
    int start = 1;
    int end = *max_element(v.begin(),v.end()); 
    while(start<end)
    {
        int sum =0;
        int mid = start + (end-start)/2;
        for(int i: v) sum = sum + (i + mid -1)/mid ;
        if(sum<=h) 
        {
            end =mid;
        }
        else start = mid+1;
    }
    cout << end;
}