//Problem Statement: Geek Land has a population of N people and each person's ability to rule the town is measured by..
// Please refer day14 text file for full problem statement.

//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    
    public:
    int RulingPair(vector<int> arr, int n) 
    { 
    
    	map<int,vector<int>> similarities;
    	int mx = -1;
    	for(int i =0;i<n;i++){
    	    similarities[sumOfDigits(arr[i])].push_back(arr[i]);
    	}
    	
    	for(auto i: similarities){
    	    sort(i.second.rbegin(),i.second.rend());
    	    if( i.second.size() >= 2) mx = max(mx,i.second[0]+i.second[1]);
    	}
    
    return mx;	
    }  
    
    int sumOfDigits(int x){
        int sum =0;
        while( x >0){
            sum += x%10;
            x = x/10;
        }
      //  cout << sum << endl;
        return sum;
    }
    
};
//Execution Time:0.84

// GFG Hints
/* 
class Solution{
    
    private:
    int digitSum(int n) 
    { 
    	int sum = 0; 
    	while (n) { 
    		sum += (n % 10); 
    		n /= 10; 
    	} 
    	return sum; 
    } 
    
    public:
    int RulingPair(vector<int> arr, int n) 
    { 
    	unordered_map<int, int> mp; 
    	int ans = -1; 
    
    	for (int i = 0; i < n; i++) { 
    		int dSum = digitSum(arr[i]); 
    
    		if (mp[dSum] != 0) { 
    			ans = max(ans, mp[dSum] + arr[i]); 
    		} 
    		mp[dSum] = max(mp[dSum], arr[i]); 
    	} 
    	return ans; 
    }   
}; */

// { Main Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
	    Solution obj;
		cout << obj.RulingPair(arr,n)<<"\n";
	}
	return 0; 
} 

// } End

// Output Win
/* 
For Input:
5
55 23 32 46 88

your output is: 
101 */