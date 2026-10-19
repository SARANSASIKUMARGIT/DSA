#include<bits/stdc++.h>
using namespace std;

            /*  Saran SK */

/*
      BRUTE FORCE APPROACH
  Problem Statement : LC242: Valid Anagram - Given two strings s and t, return true if t is an anagram of s, and false otherwise.
  Time Complexity  : O(N^2) for using nested loop for anagram check 
  Space Complexity : O(1) constant extra space
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Brute Force Approach
        if(s.length() != t.length())        //if both strings are not equal in length
            return false;
        bool isCharFound = false;
        for(int i=0;i<t.length();++i)
        {
            isCharFound = false;
            for(int j=i;j<s.length();++j)
            {
                if(t[i]==s[j])            //if current character in string t has a match in string s. 
                {                         //then swap string characters at index i and j of string s, for ignoring already visited characters in upcoming traversals
                    isCharFound = true;
                    char temp=s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    break;
                }
            }
            if(!isCharFound)      //if match is not found , return false
                return false;
        }
        return true;
    }
};

int main()
{
  Solution obj;
  string s,t;
  cout<<"Enter string1 : ";
  getline(cin,s);
  cout<<"Enter string2 : ";
  getline(cin,t);

  if(obj.isAnagram(s,t))        //calling anagram checking method
    cout<<"Two strings are Anagram"<<endl;
  else 
    cout<<"Two strings are not Anagram"<<endl;

  return 0;
}
