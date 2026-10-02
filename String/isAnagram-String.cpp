#include<iostream>
using namespace std;

      /*  Saran SK */

/*
      C++ program to check whether Two Strings are Anagram ?.

      Time Complexity  : O(N) for traversing two strings N = s1.length + s2.length,
      Space Complexity : O(N) for storing character with their count in map N = number of characters 
*/

bool isAnagram(string s, string t)
{
if(s.length() != t.length())
        return false;
    map<char,int> m;
    for(int i=0;i<s.length();++i)
        m[s[i]]++;
    for(int i=0;i<t.length();++i)
    {
        if(m[t[i]] > 0)
            m[t[i]]--;
        else
            return false;    
    }        
    return true;

}


int main()
{
    string s1,s2;
    cout<<"Enter String 1 : ";
    getline(s1,cin);
    cout<<"Enter String 2 : ";
    getline(s2,cin);
    if(isAnagram(s1,s2))
        cout<<"Two Strings are Anagram"<<endl;
    else
        cout<<"Two Strings are not Anagram"<<endl;

    return 0;
}
