//Problem Statement: Given a BST (Binary Search Tree), find the shortest range [x, y], such that,...
//Please refer day22 text file for full problem statement

// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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


// User function Template for C++

class Solution{
    
    void inOrder(Node* root,int depth,vector<int>& level,vector<int>& in){
        if(!root) return;
        
        inOrder(root->left, depth+1, level, in);
        
        in.push_back(root->data);
        level.push_back(depth);
        
        inOrder(root->right, depth+1,level, in);
    }
    
    public:
    pair<int, int> shortestRange(Node *root) {
        vector<int> level, in;
        inOrder(root,0,level,in);
        
        int max_depth = *max_element(level.begin(),level.end()) + 1;
        
        int i = 0,j = find(in.begin(), in.end(), root->data) - in.begin();
        int mid = j;
        
        unordered_map<int,int> m; 
        for(int k=0;k<=j;k++) m[level[k]]++;
        
        int l = 0,r = INT_MAX; 
        
        if(m.size()==max_depth)
        l = in[0], r = in[j];
        
        while(i<=mid && j<in.size()){
            while(i<=mid && m.size()==max_depth){
                if((in[j]-in[i])<(r-l)) 
                l = in[i], r = in[j];
                
                m[level[i]]--;
                if(m[level[i]]==0) m.erase(level[i]);
                i++;
            }
            
            while(m.size()<max_depth && j<in.size()){
                j++;
                if(j==in.size()) break;
                m[level[j]]++;
            }
        }
        return {l,r};
    }
};

// { Main Code Starts
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        pair<int, int> range = obj.shortestRange(root);
        cout << range.first << " " << range.second << "\n";
    }

    return 0;
}  // } End

//Execution Time:0.25
//Output Win
/* 
For Input:
8 3 10 2 6 N 14 N N 4 7 12 N N N N N 11 13
your output is: 
6 11 */