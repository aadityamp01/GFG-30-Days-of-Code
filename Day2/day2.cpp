// Problem Statement : Given a positive integer N. You have to find Nth natural number after removing all
// the numbers containing digit 9.
// Refer day2 text file for full problem statement.

//Initial Template for C++

#include <iostream>
using namespace std;

//User function Template for C++


class Solution{
	public:
    	long long findNth(long long N)
    {
        // code here.
        vector<int> v;
        while(N)
        {
        v.push_back(N%9);
        N /= 9;
        }
        long long ans = 0;
        for(int i=v.size()-1;i>=0;i--) ans = ans*10+v[i];
        return ans;
            }
        };

// { Main Code Starts
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n, ans;
		cin >> n;
		Solution obj;
		ans = obj.findNth(n);
		cout << ans << endl;
	}
}

// } End
