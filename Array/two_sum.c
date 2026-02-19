//***** C code snippet for TWO SUM problem in Leetcode ****
 int* returnSize1=NULL;
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    returnSize1=(int*)malloc(2*sizeof(int));
    *(returnSize1+0)=*(returnSize1+1)=-1;
    for(int s_index=0;s_index<numsSize;++s_index)
    {
        for(int j=s_index+1;j<numsSize;++j)
        {
            if(*(nums+s_index)+(*(nums+j))==target)
            {
                *(returnSize1+0)=s_index;
                *(returnSize1+1)=j;
                *returnSize=2;
                return returnSize1;
            }
        }
    }
    returnSize=0;
    return NULL;
}
