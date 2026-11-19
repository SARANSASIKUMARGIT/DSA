if(s.length()==0)
        return 0;
    unordered_map<char,ordered_map<string,int>> characterMap;
    for(int i=0;i<26;++i)
    {
        char c='A'+0;
        characterMap[c]["startIdx"]=0;
        characterMap[c]["endIdx"]=-1;
        characterMap[c]["availableKmoves"]=k;
    }
    int maxSubStringLength=1,len=s.length()-1;;
    for(int i=0;i<s.length();++i)
    {
        int currentSubStringLength,requiredMoves,remainingMoves, availableMoves,startIdx,endIdx;
        if(characterMap[s[i]]["endIdx"] == -1)
        {
            requiredMoves = i;
            availableMoves = k;
            characterMap[s[i]]["startIdx"] = 0;
            characterMap[s[i]]["endIdx"] = i;
            startIdx=characterMap[s[i]]["startIdx"];
            endIdx=characterMap[s[i]]["endIdx"];
        }
        else
        {
            startIdx=characterMap[s[i]]["startIdx"];
            endIdx=characterMap[s[i]]["endIdx"];
            requiredMoves=(i-endIdx-1);
            availableMoves = characterMap[s[i]]["availableKMoves"];
        }
        
        if(requiredMoves<=availableMoves)
        {
                
                availableMoves -= requiredMoves;
                characterMap[s[i]]["availableKmoves"] = availableMoves;
                remainingMoves = availableMoves;
                if(remainingMoves<=(len-i))
                    currentSubStringLength=(i-startIdx+1)+remainingMoves;
                else
                    currentSubStringLength =(i-startIdx+1)+(len-i);   
        }
        else
        {
            if(maxSubStringLength>(availableMoves+1))
                maxSubStringLength=availableMoves+1;
            
            startIdx = (k>(i-endIdx-1)?():();  
        }
        
        if(currentSubStringLength>maxSubStringLength)
            maxSubStringLength=currentSubStringLength;
    }
