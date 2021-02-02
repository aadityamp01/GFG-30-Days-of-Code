//Problem Statement Given an array of size N, find the number of distinct pairs {a[i], a[j]} (i != j) in the array 
//with their sum greater than 0.

// Please refer day7 text file for full problem statement.
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


//User function Template for C++


class Solution{
    
    public:
    long long binSearch(int a[],long long low,long long high,long long key)
        {
        long long mid,ans=-1;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(a[mid]+key>0)
        {
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
        }
        return ans;
        }
        
        
        long long ValidPair(int a[], int n)
        {
            sort(a,a+n);
            long long count=0;
            for(long long i=n-1;i>=1;i--)
                {
                long long j=binSearch(a,0,i-1,a[i]);
                if(j!=-1)
                count+=i-j;
                }
        return count;
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
		int array[n];
		for (int i = 0; i < n; ++i)
			cin>>array[i];
	    Solution obj;
		cout << obj.ValidPair(array, n) <<"\n";
	}
	return 0; 
} 

  // } End

//Output Win

/* 
For Input:
3
3 -2 1

your output is: 
2 */