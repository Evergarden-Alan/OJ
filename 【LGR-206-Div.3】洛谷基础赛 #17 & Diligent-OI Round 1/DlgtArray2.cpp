#include<iostream>

using namespace std;

int main(){

//处理输入
       int n,q;
       cin>>n>>q;
       int* a = new int[n];
       int** qList = new int*[q];
       int * rList = new int[q];
       for (int i = 0; i < n; i++)
       {
              cin>>a[i];
       }
       for (int i = 0; i < q; i++)
       {      
              rList[i]=0;
              int* aQ = new int[3];
              for (int h = 0; h < 3; h++)
              {
                     cin>>aQ[h];
              }
              qList[i] = aQ;
              
       }

//处理逻辑部分
       for (int i = 0; i < q; i++)
       {
              int ans = 0;
              if (qList[i][1]-qList[i][0]+1<qList[i][2])//思路中无解的情况，即第3点
              {
                     ans = -1;
              }
              else
              {
                     if (qList[i][1]-qList[i][0]==qList[i][2])//全1解
                     {

                            for (int j = qList[i][0]; j <= qList[i][1]; j++)
                            {
                                   if (a[j-1]==0)//计算把当前子数组内所有0全变成1的操作次数
                                   {
                                          ans++;
                                   }
                                   
                            }
                     }
                     else//子数组中部分值变成1的情况
                     {
                            int m = 0;
                            for (int j = qList[i][0]; j <= qList[i][1]; j++)
                            {
                                   if (a[j-1]==1)//计算当前数组中已经已经有多少1
                                   {
                                          m++;
                                   }
                                   
                            }
                            ans = qList[i][2]-m;//计算需要把子数组中多少个0变成1
                     }
                     
              }
              printf("%d\n",ans);
       }

       return 0;
}