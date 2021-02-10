//Problem Statement: Given a sorted linked list of distinct nodes (no two nodes have the same data) and an integer X...
// Please refer day15 text file for full problem statement.

#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}//End


//User function Template for C++
int triplet(int A[],int len,int X){
    int i,sum=0;
    sort(A , A+len);
    int start=0,end=len-1, res = 0;
    
    for(i=0;i<len;i++){
        start=i+1;
        end = len-1;
        sum=X-A[i];
        
        while(start<end){
             
             if(sum==(A[start]+A[end])){
               // cout<<A[i]<<A[start]<<A[end];
                start++;
                end--;
                res++;
                
            }
            else if(sum>(A[start]+A[end])){
                start++;
            }  
            else if(sum<(A[start]+A[end])){
                end--;
            }
        }
        
    }
    return res;
}

int countTriplets(struct Node* head, int x) 
{ 
    int cnt = 0;
    struct Node* temp = head;
    while(temp)
    {
        cnt++;
        temp = temp->next;
    }
    int a[cnt], i = 0;
    while(head)
    {
        a[i++] =  head->data;
        head = head->next;
    }
    
    int res = triplet(a ,cnt,x);
    
     return res;
    
} 
//Execution Time:0.08

// Output Win
/* 
For Input:
7 17
9 8 6 5 4 2 1

your output is: 
2 */