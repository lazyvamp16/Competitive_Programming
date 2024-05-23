#include<bits/stdc++.h>
using namespace std;


vector<int> subarraySum(vector<int>arr, int n, int s)
{
    vector<int> notfound(1,-1);
    vector<int> ans(2,1);
    if (n==1 && arr[0]==s) return ans;  
    if (n==1) return notfound;
    int l=0;
    int r=0;
    int wsum = arr[0];
    while(l<=r && r<n)
    {   
        if(wsum<s) wsum = wsum + arr[++r];
        else if (wsum>s)
        {   
            if(r>l) wsum = wsum - arr[l++];
            else wsum = wsum - arr[l++]+ arr[++r];
        }
        else 
        {
            ans[0]= (++l);
            ans[1]= (++r);
            return(ans);
            break;
        }
    }
    return(notfound);
}

int main()
{
    vector<int> arr{1,2,3,4,5,6,7,8,9,10};
    int s = 15;
    int n = arr.size();
    vector<int>ans=subarraySum(arr, n, s);
    cout << ans[0] << " " << ans[1] <<endl;
}