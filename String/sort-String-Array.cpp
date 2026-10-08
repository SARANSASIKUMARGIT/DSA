#include<bits/stdc++.h>

void sortStringArray(vector<string>& strs)
{
    bool isSwap=false;
    for(int i=0;i<strs.size();++i)
    {
        isSwap=false;
        for(int j=0;j<(strs.size())-1;++j)
        {
            string s1=strs[j];
            string s2=strs[j+1];
            int idx=0;
            while((s1[idx]!=0 && s2[idx]!=0)&& (s1[idx] == s2[idx]))
                ++idx;
            char c1=s1[idx],c2=s2[idx];
            if(c1>=65 && c1<=90)
                c1+=32;
            if(c2>=65 && c2<=90)
                c2+=32;        
            if(c1>c2)
            {
                isSwap=true;
                strs[j]=s2;
                strs[j+1]=s1;
            }    
        }
        if(!isSwap)
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

