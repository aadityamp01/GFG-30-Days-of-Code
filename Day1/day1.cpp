// Problem: Rearrange Geek and his Classmates 
// Refer day1 text file for full problem statement.

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

//Output Win
/* 
For Input:
6
0 5 1 2 4 3

your output is: 
0 3 5 1 4 2 
*/
