#include<bits/stdc++.h>
using namespace std;

            /*    Saran SK    */
/*
    C++ Program to sort an array of strings in ascending order

    TIME COMPLEXITY  : Worst Case O(N^2 . M) where N= number of elements in string, M = maximum length of string in array (string comparison)
    SPACE COMPLEXITY : O(1) Only Constant Space required
*/

void sortStringArray(vector<string>& strs)      //function to sort array of strings by bubble sort method
{
    bool isSwap=false;
    for(int i=0;i<strs.size();++i)
    {
        isSwap=false;           //flag variable for representing swap operation
        for(int j=0;j<(strs.size())-1;++j)          //nested loop for comparing two adjacent strings
        {
            string s1=strs[j];              //string at index 'j'
            string s2=strs[j+1];            //string at index 'j+1'
            int idx=0;                      //initial index of two strings set as 0
            while((s1[idx]!=0 && s2[idx]!=0)&& (s1[idx] == s2[idx]))    //increment the pointer index until two strings character at index 'idx' not equal 
                ++idx;                                                  //or any one string gets completely traversed(null character reached)
            char c1=s1[idx],c2=s2[idx];     //fetching the character of two strings at index 'idx'
            if(c1>=65 && c1<=90)            //converting the characters to lower case if they are alphabets
                c1+=32;
            if(c2>=65 && c2<=90)
                c2+=32;        
            if(c1>c2)               //comparing if character c1 is greater than c2
            {
                isSwap=true;        //seting flag variable to 'true' indicating a swap occurs in the current nested loop
                strs[j]=s2;         //swapping two adjacent strings
                strs[j+1]=s1;
            }    
        }
        if(!isSwap)             //if no swap occurs in the previous loop execution , then all the strings are in sorted order , therefore break the loop
            break;
    }
}

int main()
{
    vector<string> strs;
    string s;
    int n ;
    cout<<"Enter the number of strings : ";
    cin>>n;
    cin.ignore();           //clearing input buffer , to clear any characters(\n) left in input buffer
    for(int i=0;i<n;++i)
    {
        cout<<"Enter String "<<i<<" : ";        
        getline(cin,s);             //inputing string with space using getline method from 'cin' inputstream
        strs.push_back(s);          //pushing the string to the string array
    }
    
    sortStringArray(strs);              //passing the string array as reference to sort 
    
    cout<<"Sorted Array : ";
    for(auto a : strs)                  //printing the strings in the string array after sorting 
        cout<<a<< " , ";
    cout<<endl;
    
    return 0;
}
