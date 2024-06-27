//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node* reverse(node* head){
        if (head == nullptr || head->next == nullptr) return head;
        node* prev = nullptr;
        node* temp = head;
        while (temp){
            node* nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        return prev;
    }
    struct node *reverseIt (struct node *head, int k)
    { 
        node* temp = head;
        node* khead = head;
        node* lasttail = new node(-1);
        int len = 1;
        while (temp){
            if (len % k == 0){
                node* nxt = temp->next;
                temp->next = nullptr;
                lasttail->next = reverse(khead);
                if (len == k) head = lasttail->next;
                lasttail = khead;
                temp = nxt;
                khead = nxt;
            }
            else{
                temp = temp->next;
            }
            len++;
        }
        lasttail->next = reverse(khead);
        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends