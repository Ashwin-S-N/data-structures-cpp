#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*ptr, *head =NULL, *prev=NULL;
 node *getNewNode (int data)
 {
     node *new_node = new node;
     new_node->data = data;
     new_node->next= NULL;
     return new_node;
 }
  node* insertNodeEnd(node* head, int data){

    node* ptr=getNewNode(data);
    if(head==NULL)
    {
        head=ptr;
        return head;
    }
    else
    {
        node* temp=new node;
        temp=head;
        while(head->next!=NULL)
        {
            head=head->next;
        }
        head->next=ptr;
        return temp;
    }
}

int dequeue()
{
    cout<<head->data;
    head=head->next;
    return 0;
}

int displaylist (node *head)
{
    cout<<"Display List"<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
    cout<<endl;
}

int main()
{
    int x, ch;
    cout<<"Queue Linked List Implementation: \n\n";
    do
    {
        cout<<"\n\n1. enqueue2. dequeue3. Display 4.Quit\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"Enter the element to be inserted: ";
                    cin>>x;
                    head = insertNodeEnd(head,x);
                    break;
            case 2: dequeue();
                    break;
            case 3: displaylist(head);
                    break;
        }
    }
    while(ch<4);
    return 0;
}
