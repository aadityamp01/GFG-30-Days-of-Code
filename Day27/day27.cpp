//Problem Statement: Given an array of size n such that each element contains either a 'P' for policeman or a 'T' for thief...
//Please refer day27 text file for full problem statement

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
        int count=0, start,end;
        for (int i=0; i<n;i++){
            if(arr[i] == 'P'){
                if(i<k)
                start = 0;
                else
                start = i-k;
                if(i+k>=n)
                end = n-1;
                else
                end = i+k;
                
                while (start<= end){
                    if(arr[start]=='T'){
                        count+=1;
                        arr[start]='o';
                        break;
                    }
                    start++;
                }
            }
        }
        return count;
    }
};



// { Main Code Starts

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 
// }End

//Execution Time:0.07

//Output Win
/* 
For Input:
5 1
P T T P T
your output is: 
5 */