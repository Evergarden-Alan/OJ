#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <numeric>
#include <limits>
// 快速输入输出
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

// 单向链表结构
struct singly_linked_node{
       int val;
       singly_linked_node* next;
};

// 双向链表结构
struct doubly_linked_node{
       int val;
       doubly_linked_node* prev;
       doubly_linked_node* next;
};
// 单向链表的插入和删除
void insert_singly_linked_node(int val, singly_linked_node* node){
       //创建节点存储值
       singly_linked_node* new_node = new singly_linked_node();
       new_node->val = val;
       //将前驱结点的后继接入自身的next
       new_node->next = node->next;
       //将前驱结点的next接入自身
       node->next = new_node;
}

void delete_singly_linked_node(singly_linked_node* node){
       //将后继的值赋值给自身，使待删除节点名存实亡
       node->val = node->next->val;
       //标记后继节点
       singly_linked_node* temp = node->next;
       //将自身的后继修改为后继的后继
       node->next = node->next->next;
       //删除后继节点
       delete temp;
}

//双向链表插入和删除
void insert_doubly_linked_node(int val, doubly_linked_node* node){
       if (!node) return;  // 检查node是否为空
       
       //创建节点存储值
       doubly_linked_node* new_node = new doubly_linked_node();
       new_node->val = val;
       
       //设置新节点的前驱和后继
       new_node->prev = node;
       new_node->next = node->next;
       
       //如果node->next不为空，则更新其prev指针
       if (node->next) {
              node->next->prev = new_node;
       }
       
       //更新node的next指针
       node->next = new_node;
}

void delete_doubly_linked_node(doubly_linked_node* &node){
       if (!node) return;  // 空指针检查
       
       // 更新前驱节点的指针
       if (node->prev) {
              node->prev->next = node->next;
       }
       
       // 更新后继节点的指针
       if (node->next) {
              node->next->prev = node->prev;
       }
       
       // 保存当前节点指针
       doubly_linked_node* temp = node;
       // 移动指针到下一个节点
       node = node->next;
       // 删除当前节点
       delete temp;
}

//单向循环链表，就是让单向链表首尾相连
void insert_singly_circular_linked_node(int val, singly_linked_node* &node){
       //创建节点存储值
       singly_linked_node* new_node = new singly_linked_node();
       new_node->val = val;
       //判断是否是空链表：
       if(node == NULL){
              node = new_node;  // 现在可以修改调用者的指针
              new_node->next = new_node;
       }else{
              //将前驱结点的后继接入自身的next
              new_node->next = node->next;
              //将前驱结点的next接入自身
              node->next = new_node;
       }      
}

//双向循环链表，就是让双向链表首尾相连
void insert_doubly_circular_linked_node(int val, doubly_linked_node* node){
       //创建节点存储值
       doubly_linked_node* new_node = new doubly_linked_node();
       new_node->val = val;
       //判断是否是空链表：
       if(node == NULL){
              node = new_node;
              new_node->next = new_node;
              new_node->prev = new_node;
       }else{
              //将插入节点的后置节点指向当前节点的后置节点
              new_node->next = node->next;
              //将插入节点的前置节点指向当前节点
              new_node->prev = node;
              //将当前节点的后置节点指向插入节点
              node->next = new_node;
              //将插入节点的后置节点的前置节点指向插入节点
              new_node->next->prev = new_node;
       }
}

//遍历单向链表
void traverse_singly_linked_list(singly_linked_node* head){
       singly_linked_node* cur = head;
       while(cur != NULL){
              cout<<cur->val<<" ";
              cur = cur->next;
       }
       cout<<endl;
}
//遍历双向链表
void traverse_doubly_linked_list(doubly_linked_node* head){
       doubly_linked_node* cur = head;
       while(cur!= NULL){
              cout<<cur->val<<" ";
              cur = cur->next;
       }
       cout<<endl;
}

//遍历单向循环链表
void traverse_singly_circular_linked_list(singly_linked_node* head){
       if (!head) {
              cout << "空链表" << endl;
              return;
       }
       
       singly_linked_node* cur = head;
       do {
              cout << cur->val << " ";
              cur = cur->next;
       } while(cur != head);
       cout << endl;
}
//遍历双向循环链表
void traverse_doubly_circular_linked_list(doubly_linked_node* head){
       doubly_linked_node* cur = head;
       do{
              cout<<cur->val<<" ";
              cur = cur->next;
       }while(cur!= head);
       cout<<endl;
}


int main(){

       //单向链表测试
       cout<<"单向链表测试："<<endl;
       singly_linked_node* head = new singly_linked_node();
       head->val = 1;
       insert_singly_linked_node(2, head);
       traverse_singly_linked_list(head);
       insert_singly_linked_node(3, head);
       traverse_singly_linked_list(head);
       delete_singly_linked_node(head->next);
       traverse_singly_linked_list(head);

       //双向链表测试
       cout<<"双向链表测试："<<endl;
       doubly_linked_node* head_dl = new doubly_linked_node();
       head_dl->val = 1;
       insert_doubly_linked_node(2, head_dl);
       traverse_doubly_linked_list(head_dl);
       insert_doubly_linked_node(3, head_dl);
       traverse_doubly_linked_list(head_dl);
       delete_doubly_linked_node(head_dl->next);
       traverse_doubly_linked_list(head_dl);

       //单向循环链表测试
       cout<<"单向循环链表测试："<<endl;
       singly_linked_node* head_scl = new singly_linked_node();
       head_scl->val = 1;
       head_scl->next = head_scl;
       insert_singly_circular_linked_node(2, head_scl);
       traverse_singly_circular_linked_list(head_scl);
       insert_singly_circular_linked_node(3, head_scl);
       traverse_singly_circular_linked_list(head_scl);

       //双向循环链表测试
       cout<<"双向循环链表测试："<<endl;
       doubly_linked_node* head_dcl = new doubly_linked_node();
       head_dcl->val = 1;
       head_dcl->next = head_dcl;
       head_dcl->prev = head_dcl;
       insert_doubly_circular_linked_node(2, head_dcl);
       traverse_doubly_circular_linked_list(head_dcl);
       insert_doubly_circular_linked_node(3, head_dcl);
       traverse_doubly_circular_linked_list(head_dcl);      

       return 0;
}