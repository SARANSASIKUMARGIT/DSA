#include<bits/stdc++.h>
using namespace std;

            /*  Saran SK */

/*
      BRUTE FORCE APPROACH
  Problem Statement : LC36. Valid Sudoku - Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
                      1.Each row must contain the digits 1-9 without repetition.
                      2.Each column must contain the digits 1-9 without repetition.
                      3.Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

  Time Complexity  : O(N) checks N number of cells of the board
  Space Complexity : O(1) constant extra space
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows = {
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
        };                          //Vector of Vector to mark the occurence of digits from 0 to 9 in their corresponding index at corresponding i'th row
        vector<vector<int>> columns = {
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
        };                         //Vector of Vector to mark the occurence of digits from 0 to 9 in their corresponding index at corresponding i'th column
        for(int i=0;i<3;++i)
        {
            int startIdx1=i*3, endIdx1=(i*3)+2;           //range of rows
            for(int j=0;j<3;++j)
            {
                //for each iteration of this loop , one 3x3 submatrix is verified for any repetition of digits 1-9 in their box
                vector<int> freq(10,1);       //array to remember the occurence of the digits 1-9 in the current 3x3 submatrix box
                int startIdx2 = j*3, endIdx2 =(j*3)+2;    //range of colunns
                for(int m=startIdx1;m<=endIdx1;++m)
                {
                    for(int n=startIdx2;n<=endIdx2;++n)
                    {
                        if(board[m][n]=='.')              //if empty cell skip to next iteration
                            continue;
                        int num= board[m][n]-48;          //if not empty cell, then convert the character digit to integer
                        if(freq[num]<1 || rows[m][num]<1 || columns[n][num]<1)//if the digit is already occured in the current 3x3 matrix or row or column ,
                            return false;          //then INVALID MATRIX
                        freq[num]--;  //decrement all values of the corresponding digit position in all respective array to mark it's occurence
                        rows[m][num]--;
                        columns[n][num]--;
                    }
                }
            }
        }

        return true;          //if all the iterations does not return false, then the Sudoku board must be VALID = return True
    }
};

int main()
{
  Solution obj;
  char c;
  vector<vector<char>> board;

  cout<<"\t\t---- Please Give Input for 9x9 Sudoku Board ----\n\t\tOnly Give Input 1-9 or .(dot) for blank cells\n\n";

  for(int i=0;i<=8;++i)
  {
    board.push_back({});
    for(int j=0;j<=8;++j)
    {
        cout<<"Enter value for Cell ["<<i<<"]["<<j<<"] : ";
        cin>>c;
        board[i].push_back(c);
    }
  }

  if(obj.isValidSudoku(board))
    cout<<"\n\t The Sudoku Board is Valid \n";
  else
    cout<<"\n\t The Sudoku Board is InValid \n";


  return 0;
}
