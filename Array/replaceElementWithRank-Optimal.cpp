#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to Replace the elements of the array with their RANK,
    Rank of an element is the number of elements less than it + 1,
    This Program is an OPTIMAL APPROACH to find the rank of each element by 
        1.Inputing the elements of array (vector1),
        2.Copying the elements of the array to another array (vector2),
        3.Sorting the array2 for finding the rank of the element,
        4.Declare a Hash Map (unordered_map) to map the element with it's rank,
        5.Set Rank = 1 ,
        6.Traverse the array2, for every first occurence of an element in the array2 -> map the element to the value of 'rank' variable and then increment value of rank by 1 ,
        7.Skip the remaining duplicates of an element by an Inner While Loop,
        8.Finally, Traverse the original array1, and replace all the elements with it's corresponding rank from the Hash Map (unordered_set)

        TIME COMPLEXITY  : O(N Log N)  because of finding the rank by sorting the array (avoiding nested loop),
        SPACE COMPLEXITY : O(N) due to extra array (vector2) and Hash Map (unordered_map)
*/

int main()
{
    int n,num,rankIndex=1;
    vector<int> v1;
    cout<<"Enter the number of elements of the array : ";
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cout<<"Enter Element "<<i<<" : ";
        cin>>num;
        v1.push_back(num);
    }
    cout<<"\nArray Before Replaced With Rank : ";
    for(auto &a : v1)
        cout<<a<<" ";
    cout<<endl;

    vector<int> v2(v1.begin(),v1.end());   // v1=v2                 copying array1 to array2
    sort(v2.begin(),v2.end());                                      //sorting the array2

    unordered_map<int,int> rank;                                    //declaring Hash Map for storing the rank of elements in the array
    for(int i=0;i<n;++i)
    {
        //Traversing array2 for finding the rank of element 
        rank[v2[i]]=rankIndex++;                
        while(i<n-1 && v2[i]==v2[i+1])          //skipping all the other duplicate occurences of the element
            ++i;
    }

    for(int i=0;i<n;++i)
    {
        v1[i]= rank[v1[i]];                     //replacing the original array element with their rank from the Hash Map
    }

    cout<<"\nArray After Replaced With Rank : ";                //Print the result after Replacing Element With Rank
    for(auto &a : v1)
        cout<<a<<" ";

}
