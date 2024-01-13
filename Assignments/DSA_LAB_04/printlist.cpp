#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node{
    
    public:
    int num;
    Node* next=NULL;
    
};

void printll(Node* n){
    while(n!=NULL){
        cout<<n->num<<" ";
        n=n->next;
    }
}
// class Linkedlist{
    
//     Node* head;
//     Node* tail;
//     Node node;
//     public:
//     int NEntries;
//     void Create(){
//         for(int i=0;i<NEntries;i++){
//             int a;
//             cin>>a;
//             node.setEntry(a);
            
//         }
//     }    
    
// }

int main() {
    //Linkedlist ll;
   // cin>>ll.NEntries;
    int N;//=ll.NEntries;
    cin>>N;
    Node* head=nullptr;
    Node* last;
    Node* temp=head;
    for(int i=0;i<N;i++){
        
        temp=new Node();
        
        cin>>temp->num;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            last=head;
        }
        
        else{
            last->next=temp;
            last=temp;
        }
    }
    
    printll(head);
    return 0;
}
