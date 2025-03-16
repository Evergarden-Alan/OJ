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

void Inorder_Traversal_recursion(Btree_node* root){
       if (root==NULL)
       {
              return;
       }
       Inorder_Traversal_recursion(root->left_child);
       cout<<root->data;
       Inorder_Traversal_recursion(root->right_child);
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


Btree_node* create_node(int data) {
       Btree_node* node = (Btree_node*)malloc(sizeof(Btree_node));
       node->data = data;
       node->left_child = NULL;
       node->right_child = NULL;
       return node;
   }
   
   Btree_node* rebuild_with_preorder_inorder(
       int preorder[], int inorder[],
       int pre_start, int pre_end,
       int in_start, int in_end
   ) {
       if (pre_start > pre_end || in_start > in_end) {
           return NULL;
       }
   
       // 1. 找到根节点在中序中的位置
       int root_val = preorder[pre_start];
       int root_idx = -1;
       for (int i = in_start; i <= in_end; i++) {
           if (inorder[i] == root_val) {
               root_idx = i;
               break;
           }
       }
       if (root_idx == -1) {
           return NULL; // 输入不合法
       }
   
       // 2. 计算左子树和右子树的长度
       int left_size = root_idx - in_start;
       int right_size = in_end - root_idx;
   
       // 3. 创建根节点
       Btree_node* root = create_node(root_val);
   
       // 4. 递归构建左子树和右子树
       root->left_child = rebuild_with_preorder_inorder(
           preorder, inorder,
           pre_start + 1,          // 左子树前序起始
           pre_start + left_size,  // 左子树前序结束
           in_start,               // 左子树中序起始
           root_idx - 1            // 左子树中序结束
       );
   
       root->right_child = rebuild_with_preorder_inorder(
           preorder, inorder,
           pre_start + left_size + 1, // 右子树前序起始
           pre_end,                   // 右子树前序结束
           root_idx + 1,              // 右子树中序起始
           in_end                     // 右子树中序结束
       );
   
       return root;
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
       Inorder_Traversal_recursion(root);
       cout<<endl;
       Lastorder_Traversal_recursion(root);
       cout<<endl;
       

       int preorder[] = {5,4,3,2,1,6,7,8};
       int inorder[] = {1,2,3,4,5,6,7,8};
       Btree_node* root2 = rebuild_with_preorder_inorder(preorder,inorder,0,7,0,7);


       Lastorder_Traversal_recursion(root2);
       cout<<endl;

       return 0;
}