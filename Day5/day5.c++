//Problem Statement: Given a matrix of size N x M. You have to find the Kth element which will obtain while traversing the matrix spirally 
//starting from the top-left corner of the matrix.

// Refer day5 text file for full problem statement.

//Initial Template for C++

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//User function Template for C++

class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int top = 0;
        int left = 0;
        int right = m-1;
        int bottom = n-1;
        int dir =0;
        int count=0;
       
        while(top<=bottom and left<=right)
        {
            if(dir==0)
            {
                for(int i=left ;i<=right;i++)
                {
                    k--;
                    if(!k)
                    return (a[top][i]);
                }
                top++;
                dir=1;
                
            }
            if(dir==1)
            {
                for(int i=top;i<=bottom;i++)
                {
                    k--;
                    if(!k)
                    return (a[i][right]);
                }
                right--;
                dir=2;
                
               
            }
            if(dir==2)
            {
                for(int i=right;i>=left;i--)
                {
                    k--;
                    if(!k)
                    return (a[bottom][i]);
                }
                bottom--;
                dir=3;
            }
            if(dir==3)
            {
                for(int i=bottom;i>=top;i--)
                {
                    k--;
                    if(!k)
                    return (a[i][left]);
                }
                left++;
                dir=0;
            }
            
        }
        
    }

};


// { Main Code Starts

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}  // } End

// Output Win:- 
/* 
For Input:
3 3 4
1 2 3 4 5 6 7 8 9 
your output is: 
6 
*/