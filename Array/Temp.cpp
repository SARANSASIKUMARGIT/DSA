class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.length()==0)
            return 0;
        if(s.length()<=k)
            return s.length();
        unordered_map<char,map<string,int>> charMap;
        int maxSubStringLength=k,len=s.length()-1;
        for(int i=0;i<k;++i)
            charMap[s[i]]["count"]++;
        for(int i=k;i<=len;++i)
        {
            char c=s[i];
            int currentMaxLength,windowStartIndex,requiredMoves,remainingMoves;
            windowStartIndex = charMap[c]["windowStartIdx"];
            requiredMoves = (i-windowStartIndex)-charMap[c]["count"];
            if(requiredMoves<=k)
            {
                remainingMoves = k-requiredMoves;
                currentMaxLength = (i-windowStartIndex)+1;
                currentMaxLength += ( (remainingMoves<=(len-i))?remainingMoves:(len-i) );
            }
            else
            {
                windowStartIndex = i-k;
                while(windowStartIndex>0 && s[windowStartIndex-1]==c)
                    --windowStartIndex;
                for(int j=charMap[c]["windowPreviousIdx"];j<windowStartIndex;++j)
                {
                    if(s[j]==c)
                        charMap[c]["count"]--;
                }
                charMap[c]["windowPreviousIdx"] = windowStartIndex;
                currentMaxLength = i-windowStartIndex+1;
            }
            maxSubStringLength = (currentMaxLength>maxSubStringLength)?currentMaxLength:maxSubStringLength;
            charMap[c]["count"]++;
            charMap[c]["windowStartIdx"] = windowStartIndex;
        }

        return maxSubStringLength;
    }
};
