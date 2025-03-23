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

struct stack_link
{
       int data;
       stack_link* next;
};


stack_link* stack_push(stack_link* node,int value){
       stack_link* new_node = new stack_link;
       new_node->data = value;
       new_node->next = node;//头插法
       return new_node;
       
}

stack_link* stack_pop(stack_link* top){
       cout<<top->data<<endl;
       return top = top->next;
       
}

int length(stack_link* node,int index){
       if (node==NULL)
       {
              return index;
       }else{
              return length(node->next,index+1);
       }
       
}

// 打印链表
void print_stack(stack_link* head) {
       stack_link* temp = head;
       while (temp != NULL) {
           cout << temp->data << " -> ";
           temp = temp->next;
       }
       cout << "NULL" << endl;
   }


int main(){

       stack_link* top = NULL;
       // stack_link* bottom = new stack_link;

       for (int i = 0; i < 10; i++)
       {
              top = stack_push(top,i);
       }

       print_stack(top);

       // print_stack(bottom);

       top = stack_pop(top);

       print_stack(top);

       return 0;
}