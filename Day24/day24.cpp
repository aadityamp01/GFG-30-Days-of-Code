//Problem Statement:In Doraland, people have unique Identity Numbers called D-id...
//Please refer day24 problem text file for complete problem statement;

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> TopK(vector<int>& array, int k)
    {
        map<int ,int >mp;
        
        for (int i=0;i<array.size();i++)
        {
            mp[array[i]]++;
        }
        
        vector<pair<int ,int >>v;
        
        for ( auto i:mp)
        {
            v.push_back({i.second,i.first});
        }
        
        sort(v.begin(),v.end(),greater<pair<int ,int>>());
        
        vector<int >ans;
        
        for (auto i : v)
        {
            if (k>0)
            {
                ans.push_back(i.second);
                k--;
            }
        }
        return ans;
        
        
    }
};
//Execution Time:1.31   -- Time complexity is increased because of loops;


//GFG Hints solution::--------------------------------
/* 
class Solution{
    public:
    vector<int> TopK(vector<int>& array, int k)
    {
        int i,j=0;
        int arr[10002];
        for(i=0;i<10002;i++)
            arr[i] = 0;
            
        for(i=0;i<array.size();i++)
            arr[array[i]]++;
        
        vector<int>res[100002];
        
        for(i=0;i<10002;i++)
            {
                if(arr[i]!=0)
                    res[arr[i]].push_back(i);
            }
            
        vector<int>ans;
        for(i=100001;i>=0;i--)
            {
                for(int p = res[i].size()-1;p>=0;p--)
                    {
                        if(j!=k)
                            ans.push_back(res[i][p]);
                        else
                            break;
                        j++;
                    }
            }
        return ans;
    }
}; */
//Execution Time:0.62;


// { Main Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  // }End


//Output Win
/* 
For Input:
6
1 1 1 2 2 3
2
your output is: 
1 2  */
