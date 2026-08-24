#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
        C++ Program to check whether an array is a subset of another array or not ?
        An array is a subset of another array if all the elements in the arr1 are present in the arr2 .

        This Program is an OPTIMAL Approach to check whether each element in arr1 is present in arr2 by \
        using an unordered_map (Hash Map) to count the frequency of each element in the arr2.
        For each iteration of the arr1 check whether it is present in arr2 by verifying value of current element of arr1(key) is greater than 1 , if true decrease the value by 1 and continue the iteration ,
        if not return false , which means the element of current iteration of arr1 is not found in arr2 .
        Therefore it is not a subset of arr2.
        If all iterations all completed successfully without return false statement , it means all the elements of arr1 is present in arr2 .
        Therefore Arr1 is a Subset of Arr2

        TIME COMPLEXITY : O(N1+n2) for traversing both the array ,
        SPACE COMPLEXITY : O(K) where K = number of unique elements in Arr2

*/

bool isSubset(vector<int>& arr,unordered_map<int,int>& frequencyMap)     //function to verify arr1 is a subset of arr2
{
    for(auto it=arr.begin(); it != arr.end(); ++it)                 //traversing the vector by iterator
    {
        if(frequencyMap[*it]>0)
            frequencyMap[*it]--;
        else
            return false;
    }
    
    return true;
}

void inputArray(vector<int>& v,int n)
{
    int num;
    for(int i=0;i<n;++i)
    {
        cout<<"Enter Element "<<i<<" : ";
        cin>>num;
        v.push_back(num);
    }
}

int main()
{
    int n1,n2;
    cout<<"NOTE : Size of Arr1 must be less than or equal to the Size of Arr2 \n";
    cout<<"\nEnter the size of Arr1 (Array to be Verified , Subset Array) : ";
    cin>>n1;
    cout<<"\nEnter the size of Arr2 (Parent Array) : ";
    cin>>n2;
    if(n1>n2)
    {
        cout<<"The Arr1 (Child Array) size cannot be greater than the Arr2 (Parent Array)\n";
        return 1;
    }

    vector<int> v1,v2;
    inputArray(v1,n1);
    inputArray(v2,n2);

    unordered_map<int,int> frequencyMap;                //Hash Map for mapping the element of arr2 with their count
    for(int i=0;i<v2.size();++i)                    // or for(auto it=v2.begin(); it != v2.end(); ++it)
    {
        frequencyMap[v2[i]]++;                    //incrementing the frequency(count) of the element at index 'i' of arr2
    }

    if(isSubset(v1,frequencyMap))                   //if arr1 is a subset of arr2
        cout<<"Arr1 is a Subset of Arr2 \n";
    else
        cout<<"Arr1 is not a Subset of Arr2\n";


}
