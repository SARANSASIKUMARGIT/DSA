class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.length()==0)
            return 0;
        unordered_map<char,map<string,int>> charMap;
        int maxSubStringLength = 1,len=s.length()-1;
        for(int i=0;i<26;++i)
        {
            char c='A'+i;
            charMap[c]["startIdx"]=0;
            charMap[c]["endIdx"]=-1;
            charMap[c]["availableMoves"]=k;
        }

        for(int i=0;i<s.length();++i)
        {
            int currentMaxLength,startIdx,endIdx,availableMoves,requiredMoves;
            char c=s[i];
            if(charMap[c]["endIdx"]==-1)
            {
                charMap[c]["endIdx"]=i;
                requiredMoves=i;
                availableMoves = k;
                startIdx=0;
            }
            else
            {
                requiredMoves = i-charMap[c]["endIdx"]-1;
                availableMoves = charMap[c]["availableMoves"];
                startIdx = charMap[c]["startIdx"];
            }

            if(requiredMoves<=availableMoves)
            {
                availableMoves -= requiredMoves;
                endIdx = i;
                currentMaxLength = (endIdx-startIdx+1);
                if(availableMoves<=(len-i))
                    currentMaxLength += availableMoves;
                else
                    currentMaxLength += (len-i);
                charMap[c]["endIdx"] = i;
                charMap[c]["availableMoves"] = availableMoves;
            }
            else if(requiredMoves>k)
            {
                startIdx = i-k;
                endIdx = i;
                charMap[c]["startIdx"] = startIdx;
                charMap[c]["endIdx"] = endIdx;
                charMap[c]["availableMoves"] = 0;
                currentMaxLength= endIdx-startIdx+1;
            }
            else
            {
                endIdx = i;
                availableMoves = k-requiredMoves;
                currentMaxLength = (endIdx-startIdx+1);
                if(availableMoves<=(len-i))
                    currentMaxLength += availableMoves;
                else
                    currentMaxLength += (len-i);
                
                charMap[c]["endIdx"] = endIdx;
                charMap[c]["availableMoves"] = availableMoves;
            }

            maxSubStringLength = (currentMaxLength>maxSubStringLength)?currentMaxLength:maxSubStringLength;
        }

        return maxSubStringLength;
    }
};
