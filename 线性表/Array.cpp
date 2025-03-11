#include <iostream>
#include <sstream>
using namespace std;
//无序列表，按值查找
int find_by_key_with_not_orderd(int key,int A[],int length){
       int isFind=-1;
       for (int i = 0; i < length; i++)
       {
              if (key==A[i]){
                     isFind = i;
                     break;
              }
       }
       return isFind;
}
//二分查找_不平衡版
int find_by_key_with_orderd(int key,int A[],int length){
       int isFind = -1;
       int mid=length/2;
       while (mid>=0&&mid<=length)
       {
              if (key==A[mid])
              {
                     isFind=mid;
                     break;
              }
              else if (key<A[mid])
              {
                     mid = mid/2;
              }else
              {
                     mid = mid*1.5;
              }
       }
       
       return isFind;
}

//二分查找_查询次数平衡版
int find_by_key_with_orderd_balance(int key,int A[],int length){
       int isFind = -1;
       int mid=length/2;
       while (mid>=0&&mid<=length)
       {
              if (key>=A[mid])
              {
                     if (key==A[mid])
                     {
                            isFind=mid;
                            break;
                     }
                     
                     mid = mid*1.5;
              }
              else
              {
                     mid = mid/2;
              }
       }
       
       return isFind;
}
//二分查找_斐波那契版
int find_by_key_with_orderd_fibonace(int key,int A[],int length){
       int isFind = -1;
       int mid=(int) (length*((sqrt(5)-1))/2);
       while (mid>=0&&mid<=length)
       {
              if (key>=A[mid])
              {
                     if (key==A[mid])
                     {
                            isFind=mid;
                            break;
                     }
                     
                     mid = mid*1.5;
              }
              else
              {
                     mid = mid/2;
              }
       }
       
       return isFind;
}


bool insert(int value,int place,int A[],int length){
       bool isInsert = false;
       int i = place;
       
       
       for (int i = length; i != place; i--)
       {
              A[i+1] = A[i];
              isInsert = true;
       }
       
       return isInsert;
}

bool delete_by_key(int key,int A[],int length){
       bool isDelete = false;

       for (int i = 0; i < length; i++)
       {
              if (key==A[i])
              {
                     for(int j=i;j<length;j++){
                            A[j]=A[j+1];
                     }
                     isDelete = true;
                     break;
              }
              
       }
       return isDelete;
}


int main(){

       int A[10] = {1,2,3,4,5,6,7,8,9,0};
       int B[10] = {1,4,2,5,7,5,8,6,9,0};

       cout<< delete_by_key(2,A,10)<<endl;
       cout<< find_by_key_with_not_orderd(2,A,10)<<endl;
       cout<< find_by_key_with_not_orderd(2,B,10)<<endl;
       cout<<find_by_key_with_orderd_balance(7,A,10);
       // cout<<find_by_key_with_orderd_fibonace(1,A,10);
       return 0;
}