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

int stack_pop(vector<int> &mystack){
       int value = mystack[0];
       for (int i = 0; i < mystack.capacity()-1; i++)
       {
              mystack[i] = mystack[i+1];
       }
       
       return value;
}

void stack_push(vector<int> &mystack,int insert_value){
       for (int i = mystack.capacity(); i >= 0; i--)            
       {
              mystack[i+1] = mystack[i];
       }
       mystack[0] = insert_value;
}


int main(){
       vector<int> mystack;

       for (int  i = 0; i < 10; i++)
       {
              mystack.push_back(i);
       }
       
       for (int i = 0; i < mystack.capacity(); i++)
       {
              cout<<mystack[i]<<" ";
       }
       cout<<endl;

       stack_pop(mystack);
       for (int i = 0; i < mystack.capacity(); i++)
       {
              cout<<mystack[i]<<" ";
       }
       cout<<endl;

       stack_push(mystack,100);
       for (int i = 0; i < mystack.capacity(); i++)
       {
              cout<<mystack[i]<<" ";
       }
       cout<<endl;


//通过栈顶栈底指针维护push、pop
cout<<"********************"<<endl;
       vector<int> mystack2;
       int top=0,bottom=0;

       for (bottom; bottom < 10; bottom++)
       {
              mystack2.push_back(bottom);
              cout<<bottom<<" ";
       }
       cout<<endl;

       //pop
       top+=1;
       for (int i = top; i < bottom; i++)
       {
              cout<<mystack2[i]<<" ";
       }
       cout<<endl;
       
       //push
       int value = 100;

       bottom+=1;
       for (int i = bottom; i >= top; i--)
       {
              mystack2[i]=mystack2[i-1];
       }
       mystack2[top] = value;
       for (int i = top; i < bottom; i++)
       {
              cout<<mystack2[i]<<" ";
       }
       cout<<endl;



       return 0;
}