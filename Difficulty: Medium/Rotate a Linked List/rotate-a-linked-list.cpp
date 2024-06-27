//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        if (head == nullptr || head->next == nullptr) return head;
        Node* temp = head;
        // int len = 0;
        // while (temp){
        //     len++;
        //     if (temp->next) temp = temp->next;
        //     else break;
        // }
        // k = k % len;
        if (k == 0) return head;
        Node* newtail;
        int cnt = 0;
        while (temp){
            cnt++;
            if (cnt == k){
                newtail = temp;
            }
            if (temp->next) temp = temp->next;
            else break;
        }
        if (cnt++ == k) return head;
        Node* newhead = newtail->next;
        newtail->next = nullptr;
        temp->next = head;
        return newhead;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends