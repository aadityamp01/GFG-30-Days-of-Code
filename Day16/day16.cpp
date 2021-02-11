// Problem Statement: Given a string S and an integer K, the task is to reduce the string by applying the following operation..
// Please refer day16 text file for full problem statement.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//User function Template for C++

class Solution{
    public:
    string Reduced_String(int k,string s)
    {
        if(k==1)
        return("");
        
        int n = s.length();
        stack<pair<char, int>> st;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(st.empty())
            {
                st.push(make_pair(s[i],1));
                continue;
            }

            
            if(st.top().first == s[i] )
            {
                st.top().second++;
                
                if(st.top().second == k)
                    st.pop();
            }
            
            else 
            st.push(make_pair(s[i],1));
            
        }
        
        string ans="";
        while(!st.empty())
        {
            int x = st.top().second;
            ans.insert(ans.end(), x, st.top().first);
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};

// { Main Code Starts

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}  // } End

//Execution Time:0.15

/* 
For Input:
2
geeksforgeeks

your output is: 
gksforgks */