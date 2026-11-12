#include<bits/stdc++.h>
using namespace std;

        /*  Saran SK  */
/*
  C++ Program for LC74 : Search a 2D Matrix
  PS : You are given an m x n integer matrix matrix with the following two properties:
       Each row is sorted in non-decreasing order.
       The first integer of each row is greater than the last integer of the previous row.
       Given an integer target, return true if target is in matrix or false otherwise.
       You must write a solution in O(log(m * n)) time complexity.

  TIME COMPLEXITY  :  O(log N)  because of using Binary Search to reduce the search range by half 
  SPACE COMPLEXITY :  O(1)  only constant extra space

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size(),columns=matrix[0].size();
        int low=0,high=rows-1,middle;
        bool isMatchingRowFound = false;
        while(low<=high && !isMatchingRowFound)
        {
            middle=low+(high-low)/2;
            if(target>=matrix[middle][0] && target<=matrix[middle][columns-1])     //check if target value fits in the row at index 'middle'
                isMatchingRowFound = true;
            else if(target<matrix[middle][0])
                high=middle-1;
            else
                low=middle+1;
        }
        low=0,high=columns-1;
        while(low<=high && isMatchingRowFound)
        {
            int currentMiddle = low+(high-low)/2;
            if(target==matrix[middle][currentMiddle])                //perform binary search of target in the row of index 'middle'
                return true;
            else if(target<matrix[middle][currentMiddle])
                high=currentMiddle-1;
            else
                low=currentMiddle+1;
        }

        return false;
    }
};
