class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> freq;
vector<vector<int>> res;
for(int i=0;i<nums.size();++i)
    freq[nums[i]]++;

for(int i=0;i<nums.size();++i)
{
    if(!freq[nums[i]])
        continue;
    int num1=nums[i];
    int compliment1=0-num1;
    freq[num1]--;
    for(int j=i+1;j<nums.size();++j)
    {
        if(!freq[nums[j]])
            continue;
        int num2=nums[j];
        int num3=compliment1-num2;
        freq[num2]--;
        if(freq[num3])
        {
            freq[num3]--;
            res.push_back({num1,num2,num3});
            break;
        }
        freq[num2]++;
    }
}

return res;
    }
};
