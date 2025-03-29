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

void queue_push(vector<int> &queue_vector,int value,int &queue_head,int &queue_end){
       queue_end++;
       for (int i = queue_end; i > queue_head; i--)
       {
              queue_vector[i]=queue_vector[i-1];
       }
       queue_vector[queue_head]=value;
}

int queue_pop(vector<int> &queue_vector,int &queue_head,int &queue_end){
       int value=queue_vector[queue_end];
       queue_end--;
       return value;
}

int main(){

       vector<int> queue_vector;
       for (int i = 0; i < 10; i++)
       {
              queue_vector.push_back(i);
       }

       int queue_head=0;
       int queue_end=9;

       //入队
       queue_push(queue_vector,10,queue_head,queue_end);

       //输出入队后结果
       for (int i = queue_head; i <= queue_end; i++)
       {
              cout<<queue_vector[i]<<" ";
       }
       cout<<endl;

       //出队
       int value=queue_pop(queue_vector,queue_head,queue_end);
       
       cout<<value<<endl;
       //输出出队后结果
       for (int i = queue_head; i <= queue_end; i++)
       {
              cout<<queue_vector[i]<<" ";
       }
       cout<<endl;

       return 0;
}