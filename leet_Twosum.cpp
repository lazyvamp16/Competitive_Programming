#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> v;
        int temp;
        for(int i=0; i<nums.size(); i++)
        {
            temp = target - nums[i];
            if(m.find(temp)!=m.end())
            {
                v.push_back(i);
                v.push_back(m[temp]);
                return v;
            } 
            m[nums[i]]=i;
        }
        return v;
    }
};


int main()
{
    //testing
    vector<int> input{2,7,11,5};
    int t = 9;
    vector<int> result;
    Solution test;
    result = test.twoSum(input,t);
    cout << result[0] << " " << result[1];
}