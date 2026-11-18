#include<bits/stdc++.h>
using namespace std;

        /*  Saran SK  */
/*
  C++ Program for LC219. Contains Duplicate II
  PS : Given an integer array nums and an integer k, 
       return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

  TIME COMPLEXITY  :  O(N)   N = number of elements of the array
  SPACE COMPLEXITY :  O(K)   to store the index of contigious K characters of the string

*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int i;
        for(i=0;i<=k && i<nums.size();++i)
        {
            if(freq[nums[i]]>0)
                return true;
            freq[nums[i]]++;
        }
        if(i<k)
            return false;
        for(i=k+1;i<nums.size();++i)
        {
            freq[nums[i-k-1]]--;
            if(freq[nums[i]]>0)
                return true;
            freq[nums[i]]++;
        }
        return false;
    }
};
