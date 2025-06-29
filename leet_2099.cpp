#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    vector<int> nums{2,1,3,3};
    int k =2;
    vector<int>ans;
    vector<int> v = nums;
    int n = v.size();
    sort(v.begin(),v.end(),greater<int>());
    multiset<int> ms(v.begin(),v.begin()+k);
    for(int i : nums){
        if(ms.find(i)!=ms.end()) {
            ans.push_back(i);
            ms.erase(ms.find(i));
        }
    }
    for(int i : ans) cout << i << " "; 
}