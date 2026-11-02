#include<bits/stdc++.h>
using namespace std;

    /* Saran SK  */
/*
C++ program for LC1 : TWO SUM
PS  : You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
      You may assume that each input would have exactly one solution, and you may not use the same element twice.
      You can return the answer in any order.

TIME COMPLEXITY  : O(N) for traversing N number of elements in worst case
SPACE COMPLEXITY : O(N) space complexity grows linearly with number of elements of the array
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();++i)
        {
            int compliment = target-nums[i];
            if(map.count(compliment))
                return {map[compliment],i};
            map[nums[i]] = i;
        }
    return {};
    }
};
