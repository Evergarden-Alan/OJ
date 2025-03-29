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

int max_power(deque<vector<int>> &dq,int l,int r,int p){

       //获取w mod p落在区间[l,r)内的元素
       int max_v=0;
       for(size_t i=0;i<dq.size();i++){
              if(dq[i][0]%p>=l&&dq[i][0]%p<r){
                     max_v += dq[i][1];
              }
       }
       return max_v;
}



int main(){
       deque<vector<int>> dq;
       //获取测试点编号
       int t;
       cin>>t;
       //获取操作数和模数
       int n, p;
       cin>>n>>p;

       for (int i = 0; i < n; i++)
       {
              //读取指令
              string op;
              int w,v;
              cin>>op>>w>>v;
              if(op=="IF"){
                     dq.push_front({w,v});
              }
              else if(op=="IG"){
                     dq.push_back({w,v});
              }
              else if(op=="DF"){
                     dq.pop_front();
              }
              else if(op=="DG"){
                     dq.pop_back();
              }
              else{
              //计算最大值
                     int max_v = max_power(dq,w,v,p);
                     cout<<max_v<<endl;      
              }
       }
       

       return 0;
}