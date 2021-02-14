//Problem Statement: In the game of Restricted Pacman, an infinite linear path is given.
//Please refer day19 text file for full problem statement

//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_set>
using namespace std; 

//User function Template for C++

class Solution{
public:
int candies(int m, int n)
{
// Your code goes here
int x = (m*n)-(m+n);
return x/2 + 1;
}
};

// { Main Code Starts
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		Solution obj;
		cout << obj.candies(m,n)<<endl; 
	}
	return 0; 
} 
// } End
//Execution Time:0.01

// GFG solution code w.r.t tags

//Back-end complete function Template for C++

class Solution{
    public:
    int candies(int m, int n) 
    { 
    	int X = (m * n) - m - n; 
    
    	unordered_set<int> hash_set;
    	queue<int> queue; 
    	queue.push(X); 
    	hash_set.insert(X);
    
    	int count = 0; 
    	while (queue.size() > 0) 
    	{
    		int curr = queue.front(); 
    		queue.pop(); 
    		count++;
    
    		int key = curr-m;
    		if (key > 0 && (hash_set.find(key) == hash_set.end())) 
    		{
    			queue.push(key); 
    			hash_set.insert(key);
    		}
    
    		key = curr-n;
    		if (key > 0 && (hash_set.find(key) == hash_set.end())) 
    		{
    			queue.push(key); 
    			hash_set.insert(key);
    		}
    	} 
    	return count; 
    } 
};
//END


/* 
For Input:
2 5
your output is: 
2 */

// On dividing X by 2, it is 0.5 less than than the output. Bcoz our function is in integer, 
// it will rund off (x/2), so we will need to add 1 to match the output.