#include<bits/stdc++.h>

class Solution
{
bool isValidSudoku(vector<vector<char>>& board)
{
set<string> s;
for(int i=0;i<9;++i)
{
    for(int j=0;j<9;++j)
    {   
        if(board[i][j] == '.')
            continue;
        int num=board[i][j]-48;
        string row="Row"+to_string(i)+to_string(num);
        string column="Column"+to_string(j)+to_string(num);
        int boxNumber = (i/3)*3 + (j/3);
        string box="Box"+to_string(boxNumber)+to_string(num);
        
        if(s.count(row) || s.count(column) || s.count(box))
            return false;
        s.insert(row);
        s.insert(column);
        s.insert(box);
        
    }
}

return true;
}
};
