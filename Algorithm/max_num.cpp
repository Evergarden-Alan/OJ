#include<iostream>
#include<cmath>
using namespace std;

int max_num_loop(int A[],int n){
       int max = INT_MIN;
       for(int i=0;i<=n;i++)
       {
              if (max<A[i])
              {
                     max=A[i];
              }
       }
       return max;
}

int max_num_recursion(int A[],int start,int end){
       if (start == end) {
              return A[start];
          }
          // 递归调用：求剩余子数组的最大值
          int max_rest = max_num_recursion(A, start + 1, end);
          // 比较当前元素与剩余子数组的最大值
          return (A[start] > max_rest) ? A[start] : max_rest;
       
}

int main(){
       int A[] = {1,2,3,4,1,6,7,8};
       cout<< max_num_loop(A,7)<<endl;
       cout<< max_num_recursion(A,0,7)<<endl;

       return 0;
}
