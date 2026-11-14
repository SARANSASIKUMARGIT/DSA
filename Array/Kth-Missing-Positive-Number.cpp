#include<bits/stdc++.h>
using namespace std;

        /*  Saran SK  */
/*
  C++ Program for LC 1539 : Kth Missing Positive Number
  PS : Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
       Return the kth positive integer that is missing from this array.

  TIME COMPLEXITY  :  O(log N)  because of finding Closest Minimum K using Binary Search
  SPACE COMPLEXITY :  O(1)      only constant extra space

*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int closestMinimum_K=-1,currentNum,idx,low=0,high=arr.size()-1;
        while(low<=high)
        {    //finding closest Minimum K value to original given K
            int middle=low+(high-low)/2;
            int current_K=arr[middle]-(middle+1);
            if(current_K<k)
            {
                closestMinimum_K = current_K;      //storing index,nums[middle] and currentK
                idx=middle;
                currentNum = arr[middle];
                low=middle+1;
            }
            else
                high=middle-1;
        }
        if(closestMinimum_K == -1)            //if no closest Minimum K value found 
        {
            currentNum=1;
            idx=0;
            closestMinimum_K = 1;
        }
        else
        {                                    //if closest Minimum K found , increment all the variable values (to find next missing)
            ++idx;
            ++currentNum;
            ++closestMinimum_K;
        }

        while(closestMinimum_K <= k)
        {
            if(idx<arr.size() && arr[idx]==currentNum)      //if required number found, increment the index
                ++idx;
            else if(closestMinimum_K == k)                  //if currentNumber is the required Missing K th value
                break;
            else
                ++closestMinimum_K;                        //increment the closestMinimum_k , if current required number is missing
            ++currentNum;        //increment the number to find the next 
        }

        return currentNum;                //return the K th missing number
    }
};
