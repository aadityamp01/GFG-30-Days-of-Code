// Problem Statement Professor X wants his students to help each other in the chemistry lab.
//Please refer day17 text file for full problem statement
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    {
        stack<int>st;
        vector<int>res(n,-1);
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                res[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        
        return res;
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
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}
//End