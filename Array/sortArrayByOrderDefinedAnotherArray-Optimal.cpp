#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    
*/

void bubbleSortArrayByOrderDefinedByAnotherArray(vector<int> &arr1, vector<int> &rankArr)
{
    int temp;
    for(int i=0;i<rankArr.size();++i)
    {
        for(int j=0;j<rankArr.size()-i-1;++j)
        {
            if(rankArr[j]==rankArr[j+1])
            {
                if(arr1[j]>arr1[j+1])
                {
                    temp=arr1[j];
                    arr1[j]=arr1[j+1];
                    arr1[j+1]=temp;
                }
            }
            if(rankArr[j]>rankArr[j+1])
            {
                temp=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=temp;
                temp=rankArr[j];
                rankArr[j]=rankArr[j+1];
                rankArr[j+1]=temp;
            }
        }
    }
}

int main()
{
    int n1,n2,num;
    cout<<"Enter the length of Arr1 : ";
    cin>>n1;
    cout<<"Enter the length of Arr2 : ";
    cin>>n2;

    vector<int> arr1,arr2;
    vector<int> rankOrder(n1,n2+1);
    unordered_map<int,int> rankMap;
    
    for(int i=0;i<n1;++i)
    {
        cout<<"Enter Element "<<i<< " of Arr1 : ";
        cin>>num;
        arr1.push_back(num);
    }
    for(int i=0;i<n2;++i)
    {
        cout<<"Enter Element "<<i<< " of Arr2 : ";
        cin>>num;
        arr2.push_back(num);
    }

    for(int i=0;i<arr2.size();++i)
        rankMap[arr2[i]]=i+1;

    for(int i=0;i<arr1.size();++i)
    {
        if(rankMap[arr1[i]]!=0)
            rankOrder[i]=rankMap[arr1[i]];
    }

    bubbleSortArrayByOrderDefinedByAnotherArray(arr1,rankOrder);

    cout<<"Arr 1 after Sorted by the Order defined by Arr 2 : ";
    for(int i=0;i<arr1.size();++i)
        cout<<arr1[i]<< " ";
    cout<<endl;


}
