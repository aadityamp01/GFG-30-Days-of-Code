// Problem Statement: Given an integer array of size  N . You have to find sum of bit differences in all pairs
//Please refer day12 text file for full problem statement.

//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


//User function Template for C++

class Solution{
    public:
    long long sumBitDiff(int arr[], int n) 
    { 
        // Your code goes here
        int ans = 0;
        for (int i = 0; i < 32; i++) 
        {
            int count = 0;
            for (int j = 0; j < n; j++)
                if ((arr[j] & (1 << i)))
                count++;
            ans += (count * (n - count) * 2);
        } 
        return ans; 
    }
};

// { Main Code Starts
  
int main()
{
	int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int arr[n];
    	for(int i = 0; i < n; i++)
    		cin >> arr[i];
    	Solution obj;
		cout << obj.sumBitDiff(arr, n) << "\n";
    }
	return 0; 
}
// }End

// Output Win
/* 
For Input:
2
1 2
your output is: 
4 */