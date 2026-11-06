class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
vector<int> ans;

for(int i=0;i<nums2.size();++i)
    map[nums2[i]]=i;
    
for(int i=0;i<nums1.size();++i)
{
    int nextGreaterElement= -1;
    for(int j=map[nums1[i]]+1;j<nums2.size();++j)
    {
        if(nums2[j]>nums2[map[nums1[i]]])
        {
            nextGreaterElement=nums2[j];
            break;
        }
    }
    ans.push_back(nextGreaterElement);
}    

return ans;
    }
};
