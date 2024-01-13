/*
    Doubly linked list--> has data, prev node ka address, next node ka address
    
    kyu chahiye?

    it has to do with undo and redo operations! Think why...


    1.  Create NN=new Node();
        NN->next=head;
        head->prev=NN;
        head=NN;

    2.  Create NN=new Node();
        temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=NN;
        NN->prev=temp;


 ###Insert after a particular node:

     //   find address of that node;(say Node x);
        NN=new Node;
        while(temp->data!=key) temp=temp->next;
        NN->next=temp->next;
        NN->prev=temp;
    //    NN->next->prev=NN;

 ###Delete node:
        // At Head

        Node*temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;

        // At the end

        Node* temp=head;
        while(temp->next->next!=NULL) temp=temp->next;
        temp->next->prev=NULL;                          //OR delete temp->next;
        temp->next=NULL;

*/