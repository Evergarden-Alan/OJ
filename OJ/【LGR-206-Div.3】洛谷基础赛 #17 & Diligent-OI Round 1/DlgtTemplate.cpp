#include<iostream>

using namespace std;

int main(){

       int n;
       cin>>n;

       int chooseNum=0,head=0,temp=0,sum=0,tempSum=0;
       int valueList[n];
       int punishList[n];
       int choosesList[n];
       int tempList[n];
       for (int i = 0; i < n; i++)
       {
              tempList[i]=0;
              choosesList[i]=0;
              cin>>valueList[i];
       }
       for (int i = 0; i < n; i++)
       {
              cin>>punishList[i];
       }
       
       for (int i = 0; i < n; i++)
       {
              if (punishList[i]!=0)//judge cut or not
              {
                     if (punishList[i]<chooseNum)//do cut
                     {
                            sum+=valueList[i];
                            for (int j = head; j < head+punishList[i]; j++)
                            {
                                   temp+=valueList[j];
                            }
                            head = temp<valueList[i]?head+punishList[i]:head;
                            sum = temp<valueList[i]?sum+valueList[i]:sum;                  
                            choosesList[i]= temp<valueList[i]?1:0;
                            for (int j = head; j < head+punishList[i]; j++)
                            {
                                   choosesList[j]=0;
                            }
                            
                            chooseNum = temp<valueList[i]?chooseNum+1:chooseNum;
                     }else{
                            sum = valueList[i]>0?sum+valueList[i]:sum;
                            choosesList[i]= valueList[i]>=0?1:0;//值不为负就选上
                            chooseNum = sum>tempSum?chooseNum+1:chooseNum;
                     }
                     
                     
              }
              else{
                     sum = valueList[i]>0?sum+valueList[i]:sum;
                     choosesList[i]= valueList[i]>=0?1:0;//值不为负就选上
                     chooseNum = sum>tempSum?chooseNum+1:chooseNum;
              }
              tempSum = sum;
       }

       cout<<chooseNum<<endl;    
       for (int i = 0; i < n; i++)
       {
              
              if (choosesList[i]==1)
              {

                     cout<<i+1<<" ";
              }
       }
       cout<<endl;
       cout<<sum;
       
       

       return 0;
}

/*

valueList存储每格的值
punishList存储需要剔除的前n格
chooseList存储被选择的格子
head表示当前第一个被选择的格子
chooseNum表示已经选择的格子数量

整体逻辑如下：遍历valueList，当对应的punishList！=0时，判断
是否满足删除n格的条件，如果punishList>当前已选择格数的length
则不满足删除条件，直接选择。若满足删除条件，则用sum减去从head到
head+punishList[i]的value，比较后确定是否选择当前值，其实
可以转换为Sigma(head->head+punishList[i])>valueList[i]?
满足就不选，不满足就选。
最后理想的结果，chooseList应该记录了被选择的格子index，
chooseNum记录了总共选择了多少格子，sum记录了获得的值。


不是很理解，为什么样例2要选上1

*/