// Problem Statement:Given Preorder, Inorder and Postorder traversals of some tree of size N.
// Please refer day13 text file for full problem statement.

// This code solution is solved by some hints and gfg referance articles, You can refer the details in the day13 text file

//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


//Back-end complete function Template for C++

class Solution{
    public:
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
    	// Your code goes here
        if(N==0) return true;
        if(preorder[0]!=postorder[N-1]) return false;
        if (N == 1){ 
            if((preorder[0]==inorder[0]) && (inorder[0] = postorder[0])) return true; 
            else false;
        }
        int index=-1;
        for(int i=0;i<N;i++){
            if(inorder[i]==preorder[0])
              index=i;
        }
        if(index==-1){
            return false;
        }else{
          bool ret1= checktree(preorder + 1, inorder, postorder , index);
            // check for the right subtree bool ret2= checktree(preorder + index + 1, inorder
          bool ret2= checktree(preorder + index + 1, inorder + index + 1, postorder + index,N -index - 1);
        return (ret1 && ret2);
        }
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
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 

// } End

// Output Win
/* 
For Input:
5
1 2 4 5 3
4 2 5 1 3
4 5 2 3 1
your output is: 
Yes */