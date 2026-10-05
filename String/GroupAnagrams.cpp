#include<bits/stdc++.h>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res = {};
        for(auto it=strs.begin();it!=strs.end();++it)
        {
            unordered_map<char,int> frequencyMap={},tempMap;
            vector<string> temp={};
            for(int i=0;i<(*it).size();++i)
                frequencyMap[(*it)[i]]++;
            tempMap = frequencyMap;
            for(auto it2=it+1;it2!=strs.end() && *it != "";++it2)
            {
                string currentString = *it2;
                frequencyMap = tempMap;
                bool isAnagramStr=true;
                for(int j=0;j<currentString.size() && currentString.size()==(*it).size() && isAnagramStr;++j)
                {
                    if(frequencyMap[currentString[j]]>0)
                        frequencyMap[currentString[j]]--;
                    else
                        isAnagramStr=false;
                }
                if(isAnagramStr)
                {
                    temp.push_back(currentString);
                    *it2 = "";
                }
            }
            if(*it != "")
                res.push_back(temp);
        }
        return res;
    }
};
