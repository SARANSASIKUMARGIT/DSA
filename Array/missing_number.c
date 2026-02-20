//Leetcode Problem 268 Missing Number
//Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
//Saran Kumar S

int missingNumber(int* nums, int numsSize) {
    int sum=(numsSize*(numsSize+1))/2;
    for(int i=0;i<numsSize;++i)
    sum-=*(nums+i);
    return sum;
}

// ^^ C solution snippet ^^
