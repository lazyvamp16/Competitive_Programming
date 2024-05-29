// Educational Round 15
// C. Cellular Network

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool visited(int r,int m,int n, vector<int> v1, vector<int> v2)
{   
    vector<int> vis (n,0);
    int j;
    for(int i =0; i<m; i++){
        while(j<n){
            if(v1[j]>= (v2[i]-r) && v1[j] <= (v2[i]+r) ) vis[j++]=1;
            else break;
        }
    }

    for(int i: vis) if(i!=1) {
        //cout << "false";
        return false;
    }
    //cout << "true";
    return(true);
}

int main(){
    int n,m,x;
    vector<int> v1 ,v2;
    cin >> n>>m;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        v1.push_back(x);
    }
    for(int i=0; i<m; i++)
    {
        cin >> x;
        v2.push_back(x);
    }

    int start = 0;
    int end = max(abs(v1[0] - v2[m-1]), abs(v1[n-1] - v2[0]));
    while(start<end)
    {
        int mid = (start + end) /2;
        if(visited(mid,m,n,v1,v2)) end = mid;
        else start = mid + 1;
    }
    cout << end ;
}
