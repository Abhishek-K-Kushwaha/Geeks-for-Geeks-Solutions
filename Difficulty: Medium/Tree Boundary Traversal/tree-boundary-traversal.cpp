//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void leftboundary(Node* node, vector<int>& ans){
        if (node->left == nullptr && node->right == nullptr) return;
        ans.push_back(node->data);
        if (node->left) leftboundary(node->left, ans);
        else if (node->right) leftboundary(node->right, ans);
    }
    void leafs(Node* node, vector<int>& ans){
        if (node->left == nullptr && node->right == nullptr) {
            ans.push_back(node->data);
            //cout<< node->data << " ";
            return;
        }
        if (node->left) leafs(node->left, ans);
        if (node->right) leafs(node->right, ans);
    }
    void rightboundary(Node* node, vector<int>& ans){
        stack<Node*> stk;
        Node* curr = node->right;
        if (curr->right == nullptr && curr->left == nullptr) return;
        stk.push(curr);
        while (curr){
            if (curr->right) curr = curr->right;
            else if (curr->left) curr = curr->left;
            if (curr->right == nullptr && curr->left == nullptr) break;
            stk.push(curr);
        }
        while (!stk.empty()){
            ans.push_back(stk.top()->data);
            stk.pop();
        }
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root->data);
        if (root->left == nullptr && root->right == nullptr) return ans;
        if (root->left) leftboundary(root->left, ans);
        leafs(root, ans);
        if (root->right) rightboundary(root, ans);
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends