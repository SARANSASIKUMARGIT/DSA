#include<bits/stdc++.h>
using namespace std;

        /*  Saran SK  */
/*
  C++ Program for LC3. Longest Substring Without Repeating Characters
  PS : Given a string s, find the length of the longest substring without duplicate characters.

  TIME COMPLEXITY  :  O(N)   N=Length of the string
  SPACE COMPLEXITY :  O(K)   K=Maximum Length of Subarray where Frequency of K number of non-repeating characters are need to be stored in a Hash Map

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        unordered_map<char,int> map;
        int maxLength=1,currentLength=1,lastStartingIndex=1;
        map[s[0]]=1;

        for(int i=1;i<s.length();++i)
        {
            if(map[s[i]]>0 && map[s[i]]>=lastStartingIndex)
            {
                currentLength = i-map[s[i]]+1;
                lastStartingIndex = map[s[i]]+1;
            }
            else
                ++currentLength;
            map[s[i]]=i+1;
            maxLength = (currentLength>maxLength)?currentLength:maxLength;
        }

        return maxLength;
    }
};
