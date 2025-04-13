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

struct Node{
    int val;
    Node *next;
    Node *prev;
    Node(int x):val(x),next(nullptr),prev(nullptr){}
};
//头插
void insert(Node *head, int x){
    Node *node = new Node(x);
    if (head->next != nullptr)
    {
       node->next = head->next;
       head->next->prev = node;
    }
    node->prev = head;
    head->next = node;
    
}

Node* select_max(Node *head,int lo,int hi){
    Node *max_node = head;
    Node *p = head;
    for (int i = lo; i < hi; i++)
    {
       if (p->val>max_node->val)
        {
            max_node = p;
        }
        p = p->next;
    }
    return max_node;
}
//平移法
void select_sort_List(Node *head,int hi,int lo){
    Node *tail = head;
    while (tail->next!= nullptr)
    {
        tail = tail->next;
    }

           
    for (int i = lo; i < hi-1; hi--)
    {
       Node* max_node = select_max(head->next,lo,hi);
       //TODO: move max to tail
       //1.断开前后链接，并让前后连接好
       max_node->prev->next = max_node->next;
       max_node->next->prev = max_node->prev;
       //2.把max_node放到tail后面
       if (tail->next!= nullptr)
       {
        tail->next->prev = max_node;
       }
       max_node->next = tail->next;
       tail->next = max_node;
       max_node->prev = tail;
       
    }
}

void show(Node *head){
    Node *p = head->next;
    while (p!= nullptr)
    {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(){
       Node *head = new Node(-1);
       insert(head,1);
       insert(head,5);
       insert(head,3);
       insert(head,4);
       insert(head,2);
       select_sort_List(head,5,0);
       show(head);
       return 0;
}