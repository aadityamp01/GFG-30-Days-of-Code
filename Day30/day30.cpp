//Problem Statement: Penelope and her classmates are lost in the Forbidden Forest and the Devil is out to get them..
//Please refer day30 text file for full problem statement

#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

class Solution
{
    public:
    int build_bridges(string str1, string str2)
    {
        // code here
        int m=str1.length();
        int n=str2.length();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
        dp[i][0]=0;
        for(int i=0;i<=n;i++)
        dp[0][i]=0;
        for(int i=1;i<=m;i++)
        {
        for(int j=1;j<=n;j++)
        {
        if(str1[i-1]==str2[j-1])
        dp[i][j]=dp[i-1][j-1]+1;
        else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        }
        return dp[m][n];
    }
};

// { Main Code Starts
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string str1,str2;
        cin >> str1 >> str2;
        Solution obj;
        cout<<obj.build_bridges(str1,str2)<<endl;
    } 
    return 0;
} 
// } End

//Execution Time:0.01

/* 
For Input:
*@#* *#

your output is: 
2 */
