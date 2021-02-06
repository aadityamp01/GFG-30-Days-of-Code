//Problem Statement: Geek wants to send an encrypted message in the form of string S to his friend Keeg...
// Please refer day11 text file for full problem statement.
// Solution solved by taking some help from GFG articles and hints.

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


//User function Template for C++

// return a string formed by compressing string s
// do not print anything

class Solution{
    public:
    string compress(string s)
    {
        // Your code goes here
        int n=s.size();
        vector<int> v(n);
        for(int i=1;i<n;i++)
        {
	        int j=v[i-1];
	        while(j>0 && s[i]!=s[j])
	        {
		     j=v[j-1];
	        }
	        if(s[i]==s[j]) j++;
	        v[i]=j;
        }
        string ans;
        for(int i=n-1;i>=0;i--)
        {
            if(i%2)
            {
	            if(v[i]>=(i+1)/2 && (i+1)%(2*(i+1-v[i]))==0)
	            { 
		           ans.push_back('*');
		           i/=2;
		           i++;
	            }
	            else
	            {
		            ans.push_back(s[i]);
	            }
            }
            else
	        {
	            ans.push_back(s[i]);
	         }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    
    }
};

//GFG Hints Solution

/* class Solution{
    
    private:
    void fill_array(string s, int a[])
    {
        a[0] = 0;
        for(int i=1 ; i<s.size() ; i++)
        {
            int series = a[i-1];
            while(series)
            {
                if( s[series] == s[i] )
                {
                    a[i] = series+1;
                    break;
                }
                series = a[series-1];
            }
            if(!series)
                a[i] = ( s[i] == s[0] );
        }
    }
    
    public:
    string compress(string s)
    {
        int a[(int)s.size()];
        // ith element of array a stores the length of longest
        // proper suffix which is also a proper prefix
        // for substr s[0] to s[i]
        fill_array( s, a );
        
        stack <char> shortened;
        
        for(int i=s.size()-1 ; i>0 ; i--)
        // we start checking string from last index
        {
            if(i%2==0) { shortened.push(s[i]); continue; }
            // for even index, string length is odd
            // hence it cannot be divided into two
            // so we simply push ith character in stack
            
            bool star_here=0;
            // star_here will be made TRUE if substring s[0] to s[i]
            // can be divided into identical halves
            int suffix = a[i];
            int substrlen = i+1;
            // suffix and substring length are also meant for
            // substring s[0] to s[i]
            
            if(suffix*2 >= substrlen)
                if( substrlen % (substrlen-suffix) == 0 )
                    if( ( substrlen / (substrlen-suffix) ) % 2 == 0 )
                    // these conditions, if true, imply that, substring
                    // can be divided into 2 identical halves
                        star_here = 1;
            
            if(star_here)
                { shortened.push('*'); i = i/2 + 1; }
                // adding * to stack and moving index as required
            else
                shortened.push(s[i]);
                // else, simply adding character to stack
        }
        
        string ret;
        ret.push_back( s[0] );
        
        while( !shortened.empty() )
        {
            // since we analysed input string from end to start
            // removing elements from stack and pushing back to
            // output string will reverse them back to required order
            ret.push_back( shortened.top() );
            shortened.pop();
        }
        
        return ret;
    }
      
}; */


// { Main Code Starts

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        cout<< obj.compress(s) << "\n";
    }
    return 0;
}
// } End


// Output Win
/* 
For Input:
ababcababcd
your output is: 
ab*c*d */
