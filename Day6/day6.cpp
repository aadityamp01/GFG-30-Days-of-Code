// Problem Statement: In Geekland there is a grid of coins of size N x N. You have to 
//find the maximum sum of coins in any sub-grid of size K x K.
// Please refer day6 text file for full problem statement.

#include <iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

//User function Template for C++

class Solution{
    
    public:
    int Maximum_Sum(vector< vector <int> > &mat,int N,int K){
        int stripSum[N][N]; 
        
        for (int j=0;j<N;j++) 
        { 
            int sum = 0; 
            for (int i=0; i<K; i++) 
                sum += mat[i][j]; 
            stripSum[0][j] = sum; 
    
            for (int i=1; i<N-K+1; i++) 
            { 
                sum += (mat[i+K-1][j] - mat[i-1][j]); 
                stripSum[i][j] = sum; 
            } 
        } 
    
        int max_sum = INT_MIN, *pos = NULL; 
    
        for (int i=0; i<N-K+1; i++) 
        { 
            int sum = 0; 
            for (int j = 0; j<K; j++) 
                sum += stripSum[i][j]; 
            if (sum > max_sum) 
            { 
                max_sum = sum; 
                pos = &(mat[i][0]); 
            } 
    
            for (int j=1; j<N-K+1; j++) 
            { 
                sum += (stripSum[i][j+K-1] - stripSum[i][j-1]); 
    
                if (sum > max_sum) 
                { 
                    max_sum = sum; 
                    pos = &(mat[i][j]); 
                } 
            } 
        }
        return max_sum;
        
    }  
};

// { Main Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector< vector <int> > mat(N, vector< int > (N, 0));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> mat[i][j];
            }
        }

        int k; cin >> k;
        Solution obj;
        cout << obj.Maximum_Sum(mat, N, k) << "\n";
    }

    return 0;
}
// } End

// Output Win
/* 
For Input:
5
1 1 1 1 1 
2 2 2 2 2 
3 8 6 7 3 
4 4 4 4 4 
5 5 5 5 5
3
your output is: 
48 */