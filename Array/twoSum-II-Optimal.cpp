#include<bits/stdc++.h>
using namespace std;

        /* Saran SK */
/*
C++ Program for LC127 TWO SUM II - INPUT ARRAY IS SORTED  "TWO POINTER APPROACH"
PS : You are given a 1-indexed array of integers numbers that is already sorted in non-decreasing order.
    Find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
    Return the indices of the two numbers index1 and index2 as an integer array [index1, index2] of length 2.
    The tests are generated such that there is exactly one solution. You may not use the same element twice.
    Your solution must use only constant extra space.

TIME COMPLEXITY   : O(N) For Traversing N number of elements 
SPACE COMPLEXITY  : O(1) only constant extra space
*/



class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0,end=numbers.size()-1;      //two variables for pointing two opposite ends of the array
        while(start<end)
        {
            if(numbers[start]+numbers[end]==target)        
                return {start+1,end+1};                //return vector of 1-based index 
            if(numbers[start]+numbers[end]<target)     
                start++;                                //if sum of two values is less than target , then move the start pointer one step forward
            else
                end--;                                  //if sum of two values is less than target , then move the end pointer one step backward
        }

        return {};          //return empty vector if not matching pair found
    }
};
