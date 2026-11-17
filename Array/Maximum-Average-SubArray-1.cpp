#include<bits/stdc++.h>
using namespace std;

        /*  Saran SK  */
/*
  C++ Program for LC643 : Maximum Average Subarray I
  PS : You are given an integer array nums consisting of n elements, and an integer k.
       Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value.
       Any answer with a calculation error less than 10-5 will be accepted.

  TIME COMPLEXITY  :  O(N)  for traversinng N number of elements
  SPACE COMPLEXITY :  O(1)  only constant extra space required

*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maximumAverage=0;
        for(int i=0;i<k;++i)
            maximumAverage += nums[i];
        double currentSum = maximumAverage;
        maximumAverage /= k;       
        for(int i=k;i<nums.size();++i)
        {
            currentSum -= nums[i-k];
            currentSum += nums[i];
            if((currentSum/k)>maximumAverage)
                maximumAverage = (currentSum / k);
        }

        return maximumAverage;

    }
};
