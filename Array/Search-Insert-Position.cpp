#include<bits/stdc++.h>
using namespace std;

        /*  Saran SK  */
/*
  C++ Program for LC35 : Search Insert Position
  PS : Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
       You must write an algorithm with O(log n) runtime complexity.

  TIME COMPLEXITY  :  O(log N)  because of find peak element with Binary Search
  SPACE COMPLEXITY :  O(1)      only constant extra space 

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,middle;
        while(low<=high)
        {
            middle=low+(high-low)/2;
            if(nums[middle]==target)
                return middle;
            else if(nums[middle]>target)
                high = middle-1;
            else
                low = middle+1;
        }
        if(nums[middle]<target)      //if element at index 'middle' is less than target, then insert target at index 'middle+1'
            ++middle;
        return middle;
    }
};
