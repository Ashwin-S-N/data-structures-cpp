#include<>iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node* create_node(int data){
    Node *new_node=new Node;
    new_node->data=data;
    new_node->next= NULL;
    return new_node;
}
Node* push(Node *head,int data){
    Node *ptr= create_node(data);
    if(head== NULL){
        head=ptr;
    }
    else{
        ptr->next=head;
        head=ptr;
    }
    return head;
}
Node* pop(Node *head){
    if(head== NULL){
        cout<<"Underflow";
    }
    else{
        struct Node *tmp;
        tmp=head;
        head=tmp->next;
        delete(tmp);
    }
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
int main()
{
    int x,ch;
    Node *head= NULL;
    cout<<endl;
    do
    {
        cout<<"1.push 2.pop 3.Display Stack  4.Quit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cin>>x;
                head=push(x);
                break;
            case 2:
                head=pop();
                break;
            case 3:
                display(head);
                break;
            case 4:
                break;
           
        }
    }while(ch!=4);
    return 0;
}
