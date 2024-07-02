//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    Node* add(int post[], int postst, int postend, 
                int in[], int inst, int inend, map<int,int>& ind){
        if (postst > postend || inst > inend) return nullptr;
        Node* node = new Node(post[postend]);
        int i = ind[post[postend]];
        int numsonright = inend - i;
        node->left = add(post, postst, postend-numsonright-1, 
                        in, inst, i-1, ind);
        node->right = add(post, postend-numsonright, postend-1,
                        in, i+1, inend, ind);
        return node;
    }

    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int inorder[], int postorder[]) {
        map<int,int> ind;
        for (int i = 0; i < n; i++){
            ind[inorder[i]] = i;
        }
        Node* root = add(postorder, 0, n-1, inorder, 0, n-1, ind);
        return root;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends