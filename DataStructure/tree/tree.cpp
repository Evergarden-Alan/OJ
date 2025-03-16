#include<iostream>

using namespace std;

struct Btree_node
{
       int data;
       Btree_node* left_child;
       Btree_node* right_child;
};

Btree_node* creat_node(int value){
       Btree_node* new_node = (Btree_node* ) malloc(sizeof(Btree_node));
       new_node->data = value;
       new_node->left_child = NULL;
       new_node->right_child = NULL;

       return new_node;
}

Btree_node* insert_node(Btree_node* root,int value){
       if (root==NULL)
       {
              return creat_node(value);
       }

       if (value>root->data)
       {
              root->right_child = insert_node(root->right_child,value);
       }else{
              root->left_child = insert_node(root->left_child,value);
       }
}


void Preorder_Traversal_recursion(Btree_node* root){
       if (root==NULL)
       {
              return;
       }
       
       cout<<root->data;
       Preorder_Traversal_recursion(root->left_child);
       Preorder_Traversal_recursion(root->right_child);
}

void Midorder_Traversal_recursion(Btree_node* root){
       if (root==NULL)
       {
              return;
       }
       Midorder_Traversal_recursion(root->left_child);
       cout<<root->data;
       Midorder_Traversal_recursion(root->right_child);
}

void Lastorder_Traversal_recursion(Btree_node* root){
       if (root==NULL)
       {
              return;
       }
       Lastorder_Traversal_recursion(root->left_child);
       Lastorder_Traversal_recursion(root->right_child);
       cout<<root->data;
}


int main(){
       Btree_node* root = NULL;
       for (int i = 5; i < 9; i++)
       {
              root = insert_node(root,i);       
       }
       
       for (int i = 4; i > 0; i--)
       {
              root = insert_node(root,i);       
       }

       Preorder_Traversal_recursion(root);
       cout<<endl;
       Midorder_Traversal_recursion(root);
       cout<<endl;
       Lastorder_Traversal_recursion(root);
       cout<<endl;
       return 0;
}