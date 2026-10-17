#include<bits/stdc++.h>
using namespace std;

            /*  Saran SK */

/*
  Problem Statement : Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
  Time Complexity  : O(N) for traversing the sorted vector
  Space Complexity : O(1) constant extra space
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n==0)
            return 0;
        int temp_sequence=1,longest_sequence=1;
        for(int i=0;i<n-1;++i)
        {
            if(nums[i]+1 == nums[i+1])
                temp_sequence++;
            else if(nums[i]!=nums[i+1])
                temp_sequence=1;
            
            longest_sequence = (temp_sequence>longest_sequence)?temp_sequence:longest_sequence;
        }
        return longest_sequence;
    }
};

int main()
{
  Solution obj;
  vector<int> nums;
  int n,number;
  cout<<"Enter the number of elements : ";
  cin>>n;
  for(int i=0;i<n;++i)
  {
    cout<<"Enter Element "<<i<<" : ";
    cin>>number;
    nums.push_back(number);
  }

  cout<<"Longest Consecutive Sequence : "<<obj.longestConsecutive(nums)<<endl;

  return 0;
}
