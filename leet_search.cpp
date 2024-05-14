// Search Insert Position
// Binary search O(logn)

#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int mid;
    int start = 0;
    int end = nums.size();
    if(target>nums[end-1]) return end;
    while(start<=end)
    {
        mid = (start+end)/2;
        if (nums[mid] == target){
            return mid;
        } 
        else if(nums[mid]>target) {
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return(start);