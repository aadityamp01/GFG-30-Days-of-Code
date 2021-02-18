//Problem Statement: Lucy lives in house number X. She has a list of N house numbers in the society.
//Please refer day23 text file for full problem statement

//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


//User function Template for C++
class Solution{
    public:
    vector<int> Kclosest(vector<int>arr, int n, int x, int k) 
    { 
        sort(arr.begin(),arr.end());
        vector<pair<int,int> >vect;
        for(int i=0;i<n;i++)
        {
            vect.push_back(make_pair(abs(arr[i]-x),i));
        }
        sort(vect.begin(),vect.end());
        vector<int>res;
        for(int j=0;j<k;j++)
        {
            res.push_back(arr[vect[j].second]);
        }
        sort(res.begin(),res.end());
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
		int n,x,k;
		cin>>n>>x>>k; 
		vector <int> array(n);
		for (int i = 0; i < n; ++i)
			cin>>array[i];
        
        Solution obj;
		vector <int> result = obj.Kclosest(array, n, x, k); 
		for (int i = 0; i < result.size(); ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}

	return 0; 
} 
// }End

//Execution Time:0.20

/* 
For Input:
5 0 4
-21 21 4 -12 20
your output is: 
-21 -12 4 20  */