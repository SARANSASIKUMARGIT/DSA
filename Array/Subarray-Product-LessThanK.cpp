#include<bits/stdc++.h>
using namespace std;

        /*  Saran SK  */
/*
  C++ Program for LC713. Subarray Product Less Than K
  PS : You are given an array of integers nums and an integer k.
       Return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

  TIME COMPLEXITY  :  O(N)   N = number of elements of the array
  SPACE COMPLEXITY :  O(1)   only constant extra space required

*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)
            return 0;
        int startIndex=-1, subArrayCount=0,currentProduct=1;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]<k)
            {
                startIndex=i;
                break;
            }
        }
        if(startIndex == -1)
            return 0;
        for(int i=startIndex;i<nums.size();++i)
        {
            currentProduct *= nums[i];
            if(currentProduct<k && currentProduct==0)
                subArrayCount++;
            else if(currentProduct<k)
                subArrayCount+= (i-startIndex+1);
            else
            {
                while(startIndex<i)
                {
                    currentProduct /= nums[startIndex++];
                    if(currentProduct<k)
                    {
                        if(currentProduct == 0)
                        {
                            subArrayCount++;
                            break;
                        }
                        subArrayCount += (i-startIndex+1);
                        break;
                    }
                }
            }
        }

        return subArrayCount;
    }
};
