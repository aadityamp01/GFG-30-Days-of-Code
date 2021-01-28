// Problem: Rearrange Prank

//Initial template for C++

#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;


//User function template for C++

class Solution {
  public:
    void prank(long long a[], int n){
        //Code here
        for(int i=0;i<n;i++)
        a[i]+=a[(int)a[i]]%n * n;
        for(int i=0;i<n;i++)
        a[i]/=n;
        }
    };


// { Main Code

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long *a = new long long[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        ob.prank(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
}

// } End
// Time complexity: O(n), Space complexity: O(1)

// Similar referance for this problem is::
// https://www.geeksforgeeks.org/rearrange-given-array-place/
