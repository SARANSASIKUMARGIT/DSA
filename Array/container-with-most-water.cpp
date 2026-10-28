class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxIndex=0;
        int maxArea=0;
        for(int i=1;i<height.size();++i)
        {
            int lowestOfTwo = (height[i]<height[maxIndex])?height[i]:height[maxIndex];
            int currentArea = lowestOfTwo * abs(i-maxIndex);
            if(currentArea > maxArea)
                maxArea = currentArea;
            if(height[i]>height[maxIndex])
                maxIndex = i;
        }
        return maxArea;
    }
};
