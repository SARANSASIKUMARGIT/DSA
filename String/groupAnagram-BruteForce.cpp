#include<bits/stdc++.h>
using namespace std;

            /*  Saran SK */

/*
      BRUTE FORCE APPROACH
  Problem Statement : LC49. Group Anagrams - Given an array of strings strs, group the anagrams together. You can return the answer in any order.

  Time Complexity  : O(N^2) for using nested loop for checking matching anagram string 
  Space Complexity : O(1) constant extra space
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        string currentString;
        for(int i=0;i<strs.size();++i)
        {
            currentString = strs[i];      //taking string at index i as currentString
            vector<string> tempArray = {currentString};     //pushing the string into the tempArray
            sort(currentString.begin(),currentString.end());    //sorting the array
            for(int j=i+1;j<strs.size();++j)
            {
                if(currentString.length() == strs[j].length())      //if both strings length are equal
                {
                    string tempString = strs[j];                   
                    sort(tempString.begin(),tempString.end());
                    if(currentString == tempString)                 //if both strings are equal 
                    {
                        tempArray.push_back(strs[j]);               //push the string into the tempArray
                        strs[j]=strs[i+1];                        //swap the strings at index i+1 and j for moving the already visited string to front of the vector
                        strs[++i]=tempString;
                    }
                }
            }
            res.push_back(tempArray);     //pushing the temp array to the resultArray
        }
        return res;
    }
};

int main()
{
  Solution obj;
  int n;
  string s;
  vector<string> strs;

  cout<<"Enter the number of strings : ";
  cin>>n;
  cin.ignore();     //clearing input buffer (\n)
  for(int i=0;i<n;++i)
  {
    cout<<"Enter String "<<i<<" : ";    //inputing strings and pushing them into the vector
    getline(cin,s);
    strs.push_back(s);
  }

  vector<vector<string>> resAnagramArray = obj.groupAnagrams(strs);         //fetching the anagram group array by calling groupAnagrams() method in class Solution

  for(int i=0;i<resAnagramArray.size();++i)
  {
    cout<<"Anagram Group "<<i+1<<" : ";             //printing the anagram groups
    for(int j=0;j<resAnagramArray[i].size();++j)
      cout<<resAnagramArray[i][j]<<" ";
    cout<<endl;
  }



  return 0;
}
