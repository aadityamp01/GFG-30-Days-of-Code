//Problem Statement: Number of minimum picks to get 'k' pairs of socks from a drawer
// Refer day4 text file for full problem statement.

//Initial Template for C++

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//User function Template for C++

class Solution{

	public:
	int find_min(int arr[], int n, int k) {
        // code here
        int sum = 0, pairs = 0;
        for (int i=0; i<n;i++) {
            pairs+= arr[i] /2;
            if (arr[i] % 2 == 0)
            sum += (arr[i] - 2) / 2;
            else
            sum += (arr[i] - 1) / 2; 
        }
        
        if (k > pairs) return -1;
        if (k <= sum) return 2 * (k - 1) + n + 1;
        return 2 * sum + n + (k - sum);
    }

};

// { Main Code Starts

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> k;
        Solution obj;
        cout << obj.find_min(a, n, k) << endl;
    }
    return 1;
}
// } End

// Output Win:- 

/* 
For Input:
4
3 4 5 3
6
your output is: 
15 
*/