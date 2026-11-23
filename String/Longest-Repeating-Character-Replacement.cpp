#include<bits/stdc++.h>
using namespace std;

            /*    Saran SK    */
/*
    C++ Program for Leetcode Problem 424 Longest Repeating Character Replacement
    PS : You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
         Return the length of the longest substring containing the same letter you can get after performing the above operations.

    TIME COMPLEXITY  : O(N)  Optimal Approach for traversing N number of characters of the string
    SPACE COMPLEXITY : O(1) Only Constant Space required
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.length()==0)
            return 0;
        if(s.length()<=k)
            return s.length();
        unordered_map<char,int> frequencyMap;
        int maxSubStringLength=k,windowStartIndex=0,maxFreq=0;
        for(int i=0;i<s.length();++i)
        {
            frequencyMap[s[i]]++;
            if(frequencyMap[s[i]]>maxFreq)
                maxFreq=frequencyMap[s[i]];
            int windowSize = i-windowStartIndex+1;
            int requiredMovesToChange = windowSize-maxFreq;
            if(requiredMovesToChange>k)
            {
                if(maxFreq==frequencyMap[s[windowStartIndex]])
                    --maxFreq;
                frequencyMap[s[windowStartIndex]]--;
                ++windowStartIndex;
                --windowSize;
            }

            if(windowSize>maxSubStringLength)
                maxSubStringLength = windowSize;
        }
        

        return maxSubStringLength;
    }
};
