// Problem Statement: Spiderman is stuck in a difficult situation. His arch-enemy the Green Goblin...
//Please refer day25 text file for full problem statement

#include<bits/stdc++.h>
using namespace std;


struct queueNode
{
    // i, j and distance stores x and y-coordinates
    // of a matrix cell and its distance from bomb
    // respectively
    int i, j, distance;
};

class Solution{
    
    public:
 
    // These arrays are used to get row and column
    // numbers of 4 neighbors of a given cell 
    int row[4] = { -1, 0, 1, 0};
    int col[4] = { 0, 1, 0, -1 };
    
    // return true if row number and column number
    // is in range
    bool isValid(int i, int j,int m,int n)
    {
    if ((i < 0 || i > m - 1) || (j < 0 || j >n - 1))
        return false;
 
    return true;
    }
 
   // return true if current cell is an open area and its
   // distance from bomb is not calculated yet
   // i.e true when we need to visit it else false
   bool isSafe(int i, int j, vector<vector<char>>& matrix,vector<vector<int>> &output)
   {
    if (isValid(i,j,matrix.size(),matrix[0].size())==false)
    {
        return false;
    }

    if (matrix[i][j] != 'O' || output[i][j] != -1)// i.e W/B or if O then it has been visited
        return false;
 
    return true;
    }
    
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
     
     vector<vector<int>> output(M,vector<int>(N)); //making a 2D vector of MXN
    queue<queueNode> q;
 
    // finding bomb location and adding into queue
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // initialize each cell as -1
            output[i][j] = -1;
            if (matrix[i][j] == 'B')
            {
                queueNode pos = {i, j, 0};
                q.push(pos);
                // guard has 0 distance
                output[i][j] = 0;
            }
        }
    }
    
    //BFS implementation
    
    // do till queue is empty
   while (!q.empty())
    {
 
        // get the front cell in the queue and update
        // its adjacent cells
        queueNode curr = q.front();
         q.pop();
        int x = curr.i, y = curr.j, dist = curr.distance;
 
        for (int i = 0; i < 4; i++)
        {
            
            if (isSafe(x + row[i], y + col[i], matrix, output))
            // i.e we need to visit this point (x+row[i],y+col[i])
            {
                //update distance in the output matrix
                output[x + row[i]][y + col[i]] = dist + 1;
 
                queueNode pos = {x + row[i], y + col[i], dist + 1};
                // pushing ine the queue
                q.push(pos);
            }
        
        }
     
      
    }
 
   // return output matrix
   
    return output;
    } 
    
  
};

// { Main Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } End

//Execution Time:0.01

//Output win
/* 
For Input:
3 3
O O O
W B B
W O O
your output is: 
2 1 1 
-1 0 0 
-1 1 1  */
