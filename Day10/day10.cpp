//Problem Statement: Given two strings A and B, find the minimum number of times 
//A has to be repeated such that B becomes a substring of the repeated A.

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


class Solution{

    public:
    int repeatedStringMatch(string A, string B) 
    {
        // Your code goes here
        int res=1;

        int count = B.length() / A.length();
        string str = A;
        for (int i = 0; i <= count+2; i++)
        {
        if (str.find(B) != string::npos)
        {
        return res;;
        }
        else{
        str=str+A;
        res+=1;
        }
        }
        
        return -1;
    }
  
};

// { Main Code Starts


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution obj;
        cout<<obj.repeatedStringMatch(A,B)<<"\n";
    }
    return 0;
}
// } End


/* 
For Input:
abcd
cdabcdab

your output is: 
3 */