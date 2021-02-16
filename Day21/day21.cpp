// Problem Stetement: Geek has developed an effective vaccine for Corona virus and he wants each of the 
// N houses in Geek Land to have access to it..
//Please refer day21 text file for full problem statement

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


//User function Template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
public:
    int ans;
    int getCount(Node* root)
    {
        bool l1=false,r1=false;
        if(root->left==NULL&&root->right==NULL)
            return 0;
        if(root->left)
        {
            int f1=getCount(root->left);
            if(f1==0)
                l1=true;
            if(f1==2)
                r1=true;
        }
        if(root->right)
        {
            int f1=getCount(root->right);
            if(f1==0)
                l1=true;
            if(f1==2)
                r1=true;
        }
        if(l1==true)
        {
            ans++;
            return 2;
        }
        if(r1==true)
        {
            return 1;
        }
        return 0;
    }
    int supplyVaccine(Node* root){
    ans=0;
    int res=getCount(root);
    if(res==0)
        return ans+1;
    return ans;
    }
};


// { Main Code Starts.
int main() 
{
    int t;
    scanf("%d ", &t);
    while (t--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout<<ob.supplyVaccine(root)<<"\n";
    }
    return 0;
}


// }End

//Execution Time:0.20

//Output Win
/* 
For Input:
1 2 3 N N N 4 N 5 N 6
your output is: 
2 */
