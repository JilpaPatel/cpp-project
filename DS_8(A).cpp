//Binary Search Tree

#include<iostream>
using namespace std;

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *create_node(int x)
{
    struct node *temp;
    temp = new node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, int x)
{
    if(root == NULL)
    {
        root = create_node(x);
    }
    else if(x<root->info)
    {
        root->left = insert(root->left, x);
    }
    else
    {
        root->right = insert(root->right, x);
    }
    return root;
}

void inorder(struct node *temp)
{
    if(temp!=NULL)
    {
         inorder(temp->left);
         cout<<temp->info<<" ";
         inorder(temp->right);
    }
}

void preorder(struct node *temp)
{
    if(temp!=NULL)
    {
        cout<<temp->info<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct node *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->info<<" ";
    }
}

void search(struct node *temp, int x)
{
    if(temp == NULL)
    {
        cout<<"Element is not found"<<endl;
    }
    else if(temp->info == x)
    {
        cout<<"Element is founded"<<endl;
    }
    else if(x<temp->info)
    {
        search(temp->left, x);
    }
    else
    {
        search(temp->right, x);
    }
}

int main()
{
    int choice, x;
    do
    {
        cout<<"1. Insert"<<endl;
        cout<<"2. Inorder"<<endl;
        cout<<"3. Preorder"<<endl;
        cout<<"4. Postorder"<<endl;
        cout<<"5. Search"<<endl;
        cout<<"6. exit"<<endl;
        cout<<"Enetr the choice : "<<endl;
        cin>>choice;
        
        switch(choice)
        {
            case 1:
            cout<<"Enetr the value : "<<endl;
            cin>>x;
            root = insert(root, x);
            break;
            
            case 2:
            cout<<"Inorder traversal : "<<endl;
            inorder(root);
            break;
            
            case 3:
            cout<<"Preorder traversal : "<<endl;
            preorder(root);
            break;
            
            case 4:
            cout<<"Postorder traversal traversal : "<<endl;
            postorder(root);
            break;
            
            case 5:
            cout<<"Enetr the search element : "<<endl;
            cin>>x;
            search(root, x);
            break;
            
            case 6:
            cout<<"Exit from the code"<<endl;
            break;
            
            default:
            cout<<"Invalid choice"<<endl;
        }
    }
    while(choice!=6);
    return 0;
}