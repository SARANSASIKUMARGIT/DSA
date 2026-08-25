#include<bits/stdc++.h>

void captitalize_First_Last_Char_of_Words(string& str)
{
  for(int i=0;i<str.length();++i)
  {
    while(i<(str.length()) && str[i] == ' ')   //skipping all spaces
      ++i;
    if(i>=str.length()) 
        break;  
    if(str[i] >= 'a' && str[i]<='z')     //if alphabetic small case character
      str[i] -= 32;    // capitalizing by subtracting their ASCII value with 32 (ASCII value of 'a' = 97 => 97-32 = 65 'A'
    while(i<(str.length())-1 && str[i+1] != ' ')     //skipping all the characters in middle of first and last character of a word
        ++i;
    if(str[i] >= 'a' && str[i]<='z')
        str[i] -= 32;            //Capitalizing by subtracting the ASCII Value with 32
  }
}

int main() {
  string str;
  cout<<"Enter the String : ";
  
  getline(cin, str);    //inputing the string using getline() to include spaces in the string if entered by user
  
  cout<<"\n String Before Capitalizing First and Last Characters of String : "<< str<<endl;
  captitalize_First_Last_Char_of_Words(str);    //passing the string as reference parameter to capitalize first and last character of the word
  cout<<"\n String After Capitalizing First and Last Characters of String : "<< str<<endl;    //Printing the result 
  
  return 0;
}
