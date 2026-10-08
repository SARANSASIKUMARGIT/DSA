#include<bits/stdc++.h>

void sortStringArray(vector<string>& strs)
{
    bool isSwap=false;
    for(int i=0;i<strs.size();++i)
    {
        for(int j=0;j<(strs.size())-1;++j)
        {
            string s1=strs[j];
            string s2=strs[j+1];
            int idx=0;
            while
        }
    }
}

int main()
{
    vector<string> strs;
    string s;
    int n ;
    cout<<"Enter the number of strings : ";
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cout<<"Enter String "<<i<<" : ";
        getline(s,cin);
        strs.push_back(s);
    }
    
    sortStringArray(strs);
    
    for(auto a : strs)
        cout<<strs<< " , ";
    cout<<endl;
    
    return 0;
}


