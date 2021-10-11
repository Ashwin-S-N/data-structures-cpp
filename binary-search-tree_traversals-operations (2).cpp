#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};
Node* newNode(int item)
        {
    Node *temp=new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
        }
Node* search(Node *root,int data){
    if((root== NULL)||(root->data==data))return root;
    if(data<root->data)return search(root->left,data);
    return search(root->right,data);
}
Node* insert(Node *node, int data){
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(data);
    /* Otherwise, recur down the tree */
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    /* return the (unchanged) node pointer */
    return node;
}
Node* duplicates_bst(Node *node, int data){
    if (node == NULL) {
	return newNode(data);
    }
    if (data <= node->data){
        node->left = duplicates_bst(node->left, data);
    }
    else if (data > node->data){
        node->right = duplicates_bst(node->right, data);
    }
    return node;
}

void Preorder(Node *node){
    if (node == NULL)return;
    cout<<node->data<<"->";
    Preorder(node->left);
    Preorder(node->right);
}
void Postorder(Node *node){
    if (node == NULL)return;
    Postorder(node->left);
    Postorder(node->right);
    cout<<node->data<<"->";
}
void Inorder(Node  *node){
    if (node == NULL)return;
    Inorder(node->left);
    cout<<node->data<<"->";
    Inorder(node->right);
}
void Disp_range(Node *node, int x, int y)
{
   
    if (node==NULL)return;
    if (x < node->data ){
       Disp_range(node->left, x, y);
   }
    if ( x <= node->data && y >= node->data ){
        cout<<node->data<<"->";
    }
    if ( y > node->data ){
        Disp_range(node->right, x, y);
    }
}
	
int Min(Node  *node){
    while(node->left!= NULL){
	node=node->left;
    }
	return node->data;
}
int Max(Node  *node){
    while(node->right!= NULL)node=node->right;
    return node->data;
}

bool pr_level(Node* root, int level)
{
    if (root == NULL) {
        return false;
    }
    if (level == 1)
    {
        cout << root->data << "->";
        return true;
    }
    bool left = pr_level(root->left, level - 1);
    bool right = pr_level(root->right, level - 1);
    return left || right;
}
void levelord(Node* root)
{
    int level = 1;
    while (pr_level(root, level)) {
        level++;
    }
}
Node* Del_node(Node *root, int data){
    if(root== NULL)return root;
    else if(data<root->data)root->left=Del_node(root->left,data);
    else if(data>root->data)root->right=Del_node(root->right,data);
    else{
        if(root->left== NULL&&root->right==NULL)return NULL;
        else if(root->left== NULL){
            Node *temp=root->right;
            delete(root);
            return temp;
        }
        else if(root->right== NULL){
            Node *temp=root->left;
            delete(root);
            return temp;
        }
        Node* ptr = root->right;
        while (ptr && ptr->left != NULL)
            ptr = ptr->left;
        root->data=ptr->data;
        root->right=Del_node(root->right,ptr->data);
    }
    return root;
} 
Node* delete_range(Node *root,int x,int y){
    if(root== NULL)return root;
    root->left = delete_range(root->left, x, y);
    root->right = delete_range(root->right, x, y);
    if (root->data >= x && root->data <= y)
        root=Del_node(root,root->data);
    return root;
}
int dup_counter=0;
void dup_count(Node *node, int x){
    if (node == NULL)return;
    dup_count(node->left,x);
    if(node->data==x){
    	dup_counter++;
	}
    dup_count(node->right,x);
}
int main() {
    int x,y,ch,s;
    Node *root= NULL;
    Node *dup= NULL;

    cout<<endl;
    do
    {
        cout<<"1.Insert 2.Inorder 3.Preorder 4.Postorder  5. level order 6.Min value 7.Max Value\n8.Display in range 9.Delete 10.Delete in range 11.No of occurences 12.Quit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cin>>x;
                root=insert(root,x);
                dup= duplicates_bst(dup,x);
                break;
            case 2:
                Inorder(root);
                cout<<"NULL\n";
                break;
                
            case 3:
                Preorder(root);
                cout<<"NULL\n";
                break;
            case 4:
                Postorder(root);
                cout<<"NULL\n";
                break;
            case 6:
            	cout<<Min(root)<<endl;
                break;
            case 7:
            	cout<<Max(root)<<endl;
				break;
			case 5:
			    levelord(root);
			    cout<<"NULL"<<endl;
				break;
			case 8:
				cin>>x;
				cin>>y;
			    Disp_range(root,x,y);
			    cout<<"NULL"<<endl;
			    break;
			
		    case 9:
		    	cin>>x;
		    	Del_node(root,x);
			    break;	
			case 10:
				cin>>x;
				cin>>y;
				root=delete_range(root,x,y);
			    break;
			case 11:
				cin>>x;
                dup_counter=0;
                dup_count(dup,x);
                cout<<x<<" entered "<<dup_counter<<" times "<<endl;
			    break;
			case 12:
			    break;			           
        }
    }
    while(ch<13);
    return 0;
}
