#include <iostream>
#include <vector>
#include <queue>
#include <deque>
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
       deque<int> dq;
       //队尾入队
       for (int i = 0; i < 10; i++)
       {
              dq.push_back(i);
              cout<<i<<" ";
       }
       cout<<endl;
       //队尾出队
       for (int i = 0; i < 10; i++)
       {
              cout<<dq.back()<<" ";
              dq.pop_back();
       }
       cout<<endl;
       //队头入队
       for (int i = 0; i < 10; i++)
       {
              dq.push_front(i);
              cout<<i<<" ";
       }
       cout<<endl;
       //队头出队
       for (int i = 0; i < 10; i++)
       {
              cout<<dq.front()<<" ";
              dq.pop_front();
       }
       cout<<endl;
       

       //插入操作
       dq.insert(dq.begin(), 10);
       //访问操作
       cout<<dq[0]<<endl;
       //删除操作
       dq.erase(dq.begin());
       //大小操作
       cout<<dq.size()<<endl;
       //清空操作
       dq.clear();
       //判空操作
       cout<<dq.empty()<<endl;


       deque<vector<int>> dq2;
       vector<int> v={1,2};
       dq2.push_back(v);
       dq2.push_back(v);
       dq2.push_back(v);
       cout<<"***************"<<endl;
       cout<<dq.size()<<endl;

       return 0;
}