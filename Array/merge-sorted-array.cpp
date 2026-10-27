#include<bits/stdc++.h>

              /* Saran SK */
/*
C++ Program for
  LC88 : Merge Sorted Array
  PS : You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
  Merge nums1 and nums2 into a single array sorted in non-decreasing order.
  The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
  To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

  TIME COMPLEXITY  : O(N) execution times grows linearly with the size of input
  SPACE COMPLEXTIY : O(N) for using an auxilary (extra) array for storing the result array to copy it to the nums1 
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,k=0;
        vector<int> res(m+n);
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
                res[k++]=nums1[i++];
            else
                res[k++]=nums2[j++];
        }
        
        while(i<m)
            res[k++] = nums1[i++];
        while(j<n)
            res[k++] = nums2[j++];
        for(int idx=0;idx<res.size();++idx)
            nums1[idx] = res[idx];
    }
};
