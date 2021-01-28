/* Problem Statement:- Given an array of size N, find the smallest positive integer value 
that cannot be represented as sum of some elements from the array. */
// Refer day3 text file for full problem statement.

//Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//User function Template for C++
class Solution
{   
public:
    long long smallestpositive(vector<long long> array, int n)
    { 
        //Code Here
        sort(array.begin(),array.end());
        long long result = 1; 
        for (int i = 0; i < n && array[i] <= result; i++) 
            result = result + array[i]; 
        return result; 
    } 
};

// { Main Code Starts

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> array[i];
        }
        Solution ob;
        cout << ob.smallestpositive(array, n) << "\n";
    }
    return 0;
}
// } End

// Output Win:- 

/*  For Input:
    6
    1 10 3 11 6 15
    your output is: 
    2 
*/
