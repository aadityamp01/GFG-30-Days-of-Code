//Problem Statement:Geek wants to make a special space for candies on his bookshelf.Currently,..
// Please refer day8 text file for full problem statement.

//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 
        // Your code goes here
        int l=0,r=n-1;
        int ans=0,area=0;
        while (l<r)
        {
            if(height[l]<height[r]){
                area=min(height[l],height[r])*(r-l-1);
                ans = max(ans,area);
                l++;
            }
            else{
                area=min(height[l],height[r])*(r-l-1);
                ans=max(ans,area);
                r--;
            }
        }
        return ans;
    }
};


// { Main Starts

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int height[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>height[i];
    	}
    	
    	Solution obj;
    	
    	cout << obj.maxCandy(height,n)<<"\n";
    }
    return 0;
} // } End

// Output Win
/* 
For Input:
3
1 3 4
your output is: 
1 */