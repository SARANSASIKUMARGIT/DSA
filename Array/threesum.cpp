class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> freq;
vector<vector<int>> res;

sort(nums.begin(),nums.end());

for(int i=0;i<nums.size()-2;++i)
{
    if(nums[i]>0)
        break;
    int left=i+1, right=nums.size()-1;
    while(left < right)
    {
        int sum = nums[i]+nums[left]+nums[right];
        if(sum==0)
        {
            if(find(res.begin(),res.end(), vector<int>{nums[i],nums[left],nums[right]})==res.end())
                res.push_back({nums[i],nums[left],nums[right]});
            left++;
            right--;    
        }
        else if(sum<0)
            left++;
        else
            right--;    
    }
}

return res;

    }
};
