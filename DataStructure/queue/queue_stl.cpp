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

       queue<int> q;
       //入队
       for (int i = 0; i < 10; i++)
       {
              q.push(i);
              cout<<i<<" ";
       }
       cout<<endl;

       //获取队首元素
       cout<<q.front()<<endl;
       //获取队尾元素
       cout<<q.back()<<endl;
       //获取队列长度
       cout<<q.size()<<endl;
       //判断队列是否为空
       cout<<q.empty()<<endl;
       //出队
       for (int i = 0; i < 10; i++)
       {
              cout<<q.front()<<" ";
              q.pop();      
       }
       cout<<endl;

       return 0;
}