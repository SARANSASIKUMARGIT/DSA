#include<bits/stdc++.h>
using namespace std;

        /*  Saran SK  */
/*
  C++ Program for LC162 : Find Peak Element
  PS : A peak element is an element that is strictly greater than its neighbors.
      Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
      You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
      You must write an algorithm that runs in O(log n) time.

  TIME COMPLEXITY  :  O(log N)  because of find peak element with Binary Search
  SPACE COMPLEXITY :  O(K)   where K = number of recursive function call for findPeak()

*/

class Solution {
public:
    int findPeak(vector<int>& nums,int low,int high)
    {
        if(low>high)      //if invalid binary search range
            return -1;
        int middle=low+(high-low)/2;
        if((middle==0 && (nums[middle]>nums[middle+1])) || ((middle==nums.size()-1)&&(nums[middle]>nums[middle-1])))  //check peak Element at Edge Case
                return middle;
        else if((middle!=0 && middle!=nums.size()-1) && (nums[middle]>nums[middle-1] && nums[middle]>nums[middle+1]))  //check peak Element at index 'middle'
            return middle;
        int findPeakAtLeftSubArray = findPeak(nums,low,middle-1);        //find Peak Element at Left Subarray
        if(findPeakAtLeftSubArray != -1)
            return findPeakAtLeftSubArray;
        int findPeakAtRightSubArray = findPeak(nums,middle+1,high);      //find Peak Element at Right Subarray
        if(findPeakAtRightSubArray != -1)
            return findPeakAtRightSubArray;
            
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int low=0,high=nums.size()-1;

        return findPeak(nums,low,high);          //calling findPeak() to find peak element index    
    }
};
