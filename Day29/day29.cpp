//Problem Statement:Flamel is making the Elixir of Life but he is missing a secret ingredient...

//Please refer day29 text file for full problem statement

#include <bits/stdc++.h>
using namespace std;

//User function Template for C++

class Solution
{
    public:
    int maxFrequency(string str)
    {
    	// code here
    	string lps;
    	int n=str.length();
    	for(int i=1;i<n;++i)
    	{
    	    if(str.substr(0,i)==str.substr(n-i,i))
    	    {
    	        lps=str.substr(0,i);
    	        break;
    	    }
    	}
    	int ans=0;
    	for(int i=0;i<=n-lps.length();++i)
    	{
    	    if (str[i]==lps[0])
    	    {
    	        int j=0;
    	        for(j=0;j<lps.length();++j)
    	        {
    	            if(lps[j]!=str[i+j])
    	            break;
    	        }
    	        if(j==lps.length())
    	        ++ans;
    	    }
    	}
    	return ans;
    }
};

// { Main Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
   		Solution obj;
   		cout << obj.maxFrequency(str) << "\n";
   	}
    return 0;
}  // } End

//Execution Time:0.04

//Output Win
/* 
For Input:
ababaaaab
your output is: 
3 */