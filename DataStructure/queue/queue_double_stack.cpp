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



int main(){
       stack<int> push_stack;
       stack<int> pop_stack;

       //入队时，压入push_stack，出队时若pop_stack不为空，则pop_stack出栈，否则push_stack出栈压入pop_stack
       //入队
       for (int i = 0; i < 10; i++)
       {
              push_stack.push(i);
              cout<<i<<" ";
       }
       cout<<endl;
       //出队
       for (int i = 0; i < 10; i++)
       {
              if(pop_stack.empty()){
                     while (!push_stack.empty())
                     {
                            pop_stack.push(push_stack.top());
                            push_stack.pop();
                     }
              }
              cout<<pop_stack.top()<<" ";
              pop_stack.pop();
       }

       return 0;
}