#include<bits/stdc++.h>

        /* Saran SK */
/*
LC11 : Container with Most Water  BRUTE FORCE SOLUTION

PS   : You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
        Find two lines that together with the x-axis form a container, such that the container contains the most water.
        Return the maximum amount of water a container can store.
TIME COMPLEXITY  : O(N^2) for using nested loop
SPACE COMPLEXITY : O(1)   only constant extra space required

*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        for(int i=0;i<height.size();++i)
        {
            //traverse from index i to n-1 to calculate the area by length and breadth
            for(int j=i+1;j<height.size();++j)
            {
                int lowestHeight = (height[i]<height[j])?height[i]:height[j];         //length = lowest of two height ,breadth = difference between two heights (indices)
                int currentArea = lowestHeight * abs(i-j);                            //area = length * breadth  
                if(currentArea > maxArea)            //if currentArea greater than maximumArea then assign the currentArea as Maximum Area
                    maxArea = currentArea;
            }
        }
        return maxArea;
    }
};
