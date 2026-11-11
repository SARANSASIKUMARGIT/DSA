#include<bits/stdc++.h>
using namespace std;

        /*  Saran SK  */
/*
  C++ Program for LC704 : Binary Search
  PS : Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
      You must write an algorithm with O(log n) runtime complexity.

  TIME COMPLEXITY  :  O(log N)  because Binary Search
  SPACE COMPLEXITY :  O(1)   only constant extra space
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
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
        
        return -1;
    }
};
