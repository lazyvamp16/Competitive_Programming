#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    vector<int> nums{3,3,6,8};
    int target = 10;
    int cnt = 0;
    sort(nums.begin(),nums.end());
    int i = 0;
    int j = nums.size()-1;
    while(i<=j){
        if(nums[i]+nums[j]<=target){
            cnt += pow(2,(j-i));
            //cout << cnt << " " << i << " " << j << endl;
            i++;
        }
        else{
            j--;
        }
    }
    cout << "ans: " << cnt;
}