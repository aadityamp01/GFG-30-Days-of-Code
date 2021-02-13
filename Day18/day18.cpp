//Problem Statement: There are N buildings in Linear Land. They appear in a linear line one after the other..
//Please refer day18 text file for full problem statement

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


//User function template for C++

class Solution{
public:
	bool recreationalSpot(int arr[], int n){
		// Your code goes here 
		int currMin, currMax;
        currMin = currMax = arr[0];
        
        for (int i = 1; i < n; i++) {
        if (arr[i] < currMin) {
        currMin = arr[i];
        } else if (arr[i] > currMax) {
        currMax = arr[i];
        }
        
        if (arr[i] < currMax && arr[i] > currMin) {
        return true;
        }
        }
        
        return false;
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
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}  // } End

//Output Win
/* 
For Input:
6
4 7 11 5 13 2
your output is: 
True */