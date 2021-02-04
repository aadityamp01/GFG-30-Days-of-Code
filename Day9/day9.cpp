//Problem Statement: Professor McGonagall teaches transfiguration at Hogwarts. 
//She has given Harry the task of changing himself into a cat.

// Please refer day9 text file for full problem statement.

//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	// Your code goes here
    	int rep[256];
    	memset(rep,0,sizeof(rep));
    	
    	for(char ch:A)
    	rep[ch-'0']++;
    	for(char ch:B)
    	rep[ch-'0']--;
    	for(int x:rep)
    	{
    	    if(x!=0)
    	    return -1;
    	}
    	
    	int i=A.length()-1,j=B.length()-1,count=0;
    	while(i>=0 && j>=0)
    	{
    	    if(A[i]==B[j])
    	    {
    	        i--; j--;
    	    }
    	    else
    	    {
    	        count++;
    	        i--;
    	    }
    	}
    	return count;
    }
};

// { Main Code Starts


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } End



/* 
For Input:
GEEKSFORGEEKS FORGEEKSGEEKS

your output is: 
3 */