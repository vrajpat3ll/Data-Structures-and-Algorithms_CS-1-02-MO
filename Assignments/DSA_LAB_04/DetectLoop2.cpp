//{ Driver Code Starts
//Initial template code for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends






//User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/




//Function to check if the linked list has a loop.
bool detectLoop(Node* head)
{
  // your code here
    Node* fastptr=head;
    Node* slowptr=head;
    
    while(fastptr!=NULL&& fastptr->next!=NULL){
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        
        if(fastptr==slowptr) return true;
    }
    
    return false;
}

//{ Driver Code Starts.

int main()
{
    
    int n, num;
    cin>>n;

    Node *head, *tail;
    cin>> num;
    head = tail = new Node(num);

    for(int i=0 ; i<n-1 ; i++)
    {
        cin>> num;
        tail->next = new Node(num);
        tail = tail->next;
    }

    int pos;
    cin>> pos;
    loopHere(head,tail,pos);

    if(detectLoop(head))
        cout<< "True\n";
    else
        cout<< "False\n";
    return 0;
}

// } Driver Code Ends