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

void enqueue(vector<int>& queue_cycle, int value,int &front,int &rear){
       if ((rear + 1) % queue_cycle.size() == front)
       {
              cout<<"queue is full"<<endl;
              return;
       }
       queue_cycle[rear] = value;
       rear = (rear + 1) % queue_cycle.size();
       
}

int dequeue(vector<int>& queue_cycle,int &front,int &rear){
       if (front == rear)
       {
              cout<<"queue is null"<<endl;
              return -1;
       }
       int value = queue_cycle[front];
       front = (front + 1) % queue_cycle.size();
       return value;
       
}

int main(){

       vector<int> queue_cycle(10);
       int front = 0,rear = 0;
       //循环队列：利用定长数组和头尾指针维护一个虚拟的环形队列
       //循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
       //入队初始化循环队列，长度为10
       for (int i=0 ; i < 10; i++)
       {
              enqueue(queue_cycle, i,front,rear);
       }

       cout<<"origin queue:";
       for (int i = front; i < rear; i++)
       {
              cout<<queue_cycle[i]<<" ";
       }
       cout<<endl;

       //出队
       int value = dequeue(queue_cycle,front,rear);
       cout<<value<<endl;
       cout<<"first dequeue:";
       for (int i = front; i < rear; i++)
       {
              cout<<queue_cycle[i]<<" ";
       }
       cout<<endl;
       //再次入队
       enqueue(queue_cycle, 10,front,rear);
       cout<<"second enqueue:";
       for (int i = front; (i % queue_cycle.size()) != rear; i++)
       {
              cout<<queue_cycle[i]<<" ";
       }
       cout<<endl;
       
       return 0;
}