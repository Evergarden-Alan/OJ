#include<iostream>

using namespace std;

int main(){

//read inputs
       int n;
       scanf("%d",&n);

       int** marks = new int *[n];
       for (int i = 0; i < n; i++)
       {
              marks[i] = new int[3];
              for (int j = 0; j < 3; j++)
              {               
                     cin>>marks[i][j];
                     
              }
       }
//calculate payment
       int subwayPrice[n];
       int subwayTime[n];
       int pay=0;
       for (int markIndex = 0; markIndex < n; markIndex++)
       {
              //乘地铁
              if (marks[markIndex][0]==0)
              {
                     pay += marks[markIndex][1];
                     subwayPrice[markIndex] = marks[markIndex][1];
                     subwayTime[markIndex] = marks[markIndex][2];
              }
              //乘公交
              else{
                     bool needPay=true;
                     subwayPrice[markIndex] = 0;
                     subwayTime[markIndex] = 0;
                     //查看当前时刻前没有被抵扣的票
                     for (int j = 0; j < markIndex; j++)
                     {
                            //查看在可用时间范围内，并且票价高于当次公交价格的优惠票
                            if ((marks[markIndex][2] - subwayTime[j]<=45)&&(marks[markIndex][1]<=subwayPrice[j]))
                            {
                                   //一次只能用一张优惠票
                                   //抵扣过一次后不再计算,抵扣策略为地铁票价大于公交票价方可全额抵扣,否则全部不抵扣
                                   /*
                                          由于此时手中只有第五条记录中乘坐地铁获得的优惠票有效，而本次公交车的票价为 6 元，
                                          高于第五条记录中地铁的票价 5 元，所以不能使用优惠票，花费 6 元乘坐公交车。
                                   */
                                  subwayPrice[j] = 0;
                                  needPay = false;
                                  break;
                            }
                     }
                     if (needPay)
                     {
                            pay += marks[markIndex][1];
                     }
                     

              }
       }
       
       cout<<pay<<endl;

       return 0;
}