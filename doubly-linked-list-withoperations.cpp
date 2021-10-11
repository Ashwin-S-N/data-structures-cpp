#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
};
Node* create_node(int data){
    Node *new_node=new Node;
    new_node->data=data;
    new_node->next= NULL;
    new_node->prev=NULL;
    return new_node;
}
Node* beg_insert(Node *head,int data){
    Node *ptr= create_node(data);
    if(head== NULL){
        head=ptr;
    }
    else{
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
    }
    return head;
}
Node* end_insert(Node *head,int data){
    Node *ptr= create_node(data);
    if(head== NULL){
        head=ptr;
    }
    else{
        Node *last=head;
        while(last->next!= NULL)last=last->next;
        last->next=ptr;
        ptr->prev=last;
    }
    return head;
}
Node* search(Node *head,int s){
    Node *ptr= NULL;
    Node *temp=head;
    while(head!=NULL){
        if(temp->data==s){
            ptr=temp;
            break;
        }
        temp=temp->next;
    }
    return ptr;
}
Node* insert_mid(Node *head,int data1,int data){
    Node *temp=search(head,data1);
    Node *ptr= create_node(data);
    Node *temp1=temp->next;
    temp->next=ptr;
    ptr->prev=temp;
    ptr->next=temp1;
    temp1->prev=ptr;
    return head;
}

void display(Node *head){
    cout<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
void rev_display(Node *head){
    cout<<endl;
    while(head->next!=NULL)head=head->next;
    while(head!= NULL){
        cout<<head->data<<"->";
        head=head->prev;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    int x,y,ch,s;
    Node *head= NULL;
    cout<<endl;
    do
    {
        cout<<"1.beginning insert 2. middle insert  3. end insert 4. Display forward  5.display reverse  6.Quit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cin>>x;
                head=beg_insert(head,x);
                break;
            case 2:
                cin>>x;
                cin>>y;
                head=insert_mid(head,x,y);
                break;
            case 3:
                cin>>x;
                head=end_insert(head,x);
                break;
            case 4:
                display(head);
                break;
            case 5:
                rev_display(head);
                break;
            case 6:
                break;
            
        }
    }
    while(ch<7);
}
