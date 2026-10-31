#include<bits/stdc++.h>
using namespace std;

      /*  Saran SK  */

/*
OPTIMAL - Two Pointer Approach
LC11 : Container with Most Water
PS : You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
    Find two lines that together with the x-axis form a container, such that the container contains the most water.
    Return the maximum amount of water a container can store.

TIME COMPLEXITY  : O(N) traversing N number of elements
SPACE COMPLEXITY : O(1) only constant extra space
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int leftEnd = 0, rightEnd = height.size()-1;
        while(leftEnd < rightEnd)              //looping till the leftend pointer less than the rightEnd
        {
            int lowestOfTwo = (height[leftEnd]<height[rightEnd])?height[leftEnd]:height[rightEnd];    //length (select the smallest height of the two)
            int breadth = rightEnd-leftEnd;                                                          //breadth = distance between two points 
            int currentArea = lowestOfTwo * breadth;          //calculate currentArea
            if(currentArea>maxArea)                           //if currentArea is greater than the maximum area , then assign the currentArea to maxArea
                maxArea = currentArea;
            if(height[leftEnd]<height[rightEnd])          //if height at index 'leftEnd' is lesser than height at index 'rightEnd'
                ++leftEnd;                              //move the left pointer one step towards the right
            else
                --rightEnd;                            //else move the right pointer one step towards the left 
        }

        return maxArea;          //return the maximum possible area 
    }
};
