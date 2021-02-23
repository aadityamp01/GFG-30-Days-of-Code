// Problem Statement: A gallery with plants is divided into n parts, numbered : 0,1,2,3...n-1. There are provisions...
//Please refer day28 text file for full problem statement

#include <bits/stdc++.h>
using namespace std;


//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<int> dp(n,-1);
        int left,right;
        for (int i = 0; i < n; i++) 
        {
            if(gallery[i] != -1)
            {
                right = min(i + gallery[i], n-1);
                left = max(i - gallery[i], 0);
                dp[left] = max(dp[left], right);
            }
        }
        right = dp[0];
        int nxtidx=-1,ans = 1;
        for (int i = 0; i < n; i++)
        {
            nxtidx = max(nxtidx,dp[i]);
            if(i > right && nxtidx <= i-1)
            {
                return -1;
            }
            if (i == right + 1)
            {
                right = nxtidx;
                ans++;
            }
        }
        return ans;
    }
};


// { Main Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}
// }End
//Execution Time:0.09

//Output Win
/* 
For Input:
8
1 0 4 2 0 6 2 4
your output is: 
1 */