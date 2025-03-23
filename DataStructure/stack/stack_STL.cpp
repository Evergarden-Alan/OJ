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

       stack<int> st1,st2;

       cout<<"st1 empty?\t"<<st1.empty()<<endl;

       for (int i = 0; i < 10; i++)
       {
              st1.push(i);
       }
       

       st2 = st1;
       st1.pop();

       cout<<"st2.top:\t"<<st2.top()<<endl;
       cout<<"st2.size:\t"<<st2.size()<<endl;
       cout<<"st1.top:\t"<<st1.top()<<endl;
       cout<<"st1.size:\t"<<st1.size()<<endl;


       cout<<"st1.empty:\t"<<st1.empty()<<endl;
       cout<<"st1.empty.type:\t"<<typeid(st1.empty()).name()<<endl;




       return 0;
}