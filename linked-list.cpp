#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*head= NULL;

Node* create_node(int data){
    Node *ptr= new Node;
    ptr->data=data;
    ptr->next= NULL;
    return ptr;
}

void beg_insert(int data){
    Node *ptr= create_node(data);
    if(head== NULL){
        head=ptr;
    }
    else{
    	head->prev=ptr
        ptr->next=head;
        head=ptr;
    }
}

Node* search(int data1){
    Node *temp=head;
    while(temp!=NULL){
        if(temp->data==data1){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

void mid_insert(int data,int data1){
    Node *ptr= create_node(data);
    Node *temp=search(data1);
    Node *temp1=temp->next;
    temp->next=ptr;
    ptr->next=temp1;
}

void end_insert(int data){
    Node *ptr= create_node(data);
    Node *temp=head;
    if (head== NULL)head=ptr;
    else{
        while(temp->next!= NULL)temp=temp->next;
        temp->next=ptr;
    }
}

void del_beg(){
    if(head->next== NULL)head= NULL;
    else{
        Node *temp=head;
        head=temp->next;
        delete(temp);
    }
}

void del_mid(int data){
    Node *ptr=search(data);
    Node *temp=ptr->next;
    ptr->next=temp->next;
    delete(temp);
}

void del_end(){
    if(head->next== NULL)head= NULL;
    else{
        Node *temp=head;
        while(temp->next->next!=NULL)temp=temp->next;
        Node *ptr=temp->next;
        delete(ptr);
        temp->next= NULL;
    }
}

void display(){
    Node *ptr=head;
    while(ptr!= NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL"<<endl;
}
bool prime(int x){
    for(int i=2;i<x;i++){
        if(x%i==0)return false;
    }
    return true;
}

void display_prime(){
    Node *ptr=head;
    while(ptr!= NULL){
        if(prime(ptr->data))cout<<ptr->data<<",";
        ptr=ptr->next;
    }
    cout<<endl;
}

int main(){
    int ch,x,y;
    do
    {
        cout<<"1.Begin Insert 2.Middle Insert 3.End Insert 4.Begin del 5.Mid del 6.End del 7.Display list 8. Display all Primes 9.Quit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cin>>x;
                beg_insert(x);
                break;
            case 2:
                cout<<"Enter the Element present in the list after which node should be added : ";
                cin>>x;
                cout<<endl;
                cout<<"Enter the desired element : ";
                cin>>y;
                cout<<endl;
                mid_insert(y,x);
                break;
            case 3:
                cin>>x;
                end_insert(x);
                break;
            case 4:
                del_beg();
                break;
            case 5:
                cout<<"Enter the element present in list after which node should be deleted:";
                cin>>x;
                cout<<endl;
                del_mid(x);
                break;
            case 6:
                del_end();
                break;
            case 7:
                display();
                break;
            case 8:
                display_prime();
                break;    
            case 9:
                break;
            
        }
    }while(ch<9);

}
