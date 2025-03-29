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

       vector<int> queue_vector;
       //通过队头队尾指针维护队列
       int queue_head=0,queue_end=0;
       cout<<"head->";
       for (int i = queue_head; i < 10; i++)
       {
              queue_vector.push_back(i);
              queue_end++;
              cout<<i<<" ";
       }
       cout<<"->end"<<endl;
       
       //出队
       int value=queue_vector[queue_head];
       queue_head++;
       cout<<value<<endl;
       //输出出队后结果
       cout<<"head->";
       for (int i = queue_head; i < queue_end; i++)
       {
              cout<<queue_vector[i]<<" ";
       }
       cout<<"->end"<<endl;

       //入队
       queue_vector.push_back(10);
       queue_end++;
       //输出入队后结果
       cout<<"head->";
       for (int i = queue_head; i < queue_end; i++)
       {
              cout<<queue_vector[i]<<" ";
       }
       cout<<"->end"<<endl;

       return 0;
}