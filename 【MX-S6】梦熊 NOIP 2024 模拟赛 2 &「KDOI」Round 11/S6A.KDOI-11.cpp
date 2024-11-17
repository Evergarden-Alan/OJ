#include<iostream>
#include<list>

using namespace std;

struct file
{
       int startTime;
       int spendTime;
       int endTime;
};

struct printer
{
       int printFileNum;
       list<int> fileList;
};



int main(){

       int n;//文件数量
       int m;//打印机数量
       cin>>n>>m;

       //构建m个队列；
       queue<file> printers[m];

       list<file> files;
       
       int timeLine=0;
       //获取文件
       for (int i = 0; i < n; i++)
       {
              int s;//打印时间
              int t;//下发时间
              cin>>s>>t;
              timeLine = s+t>timeLine?s+t:timeLine;//确定时间线
              file a;
              a.startTime=t;
              a.spendTime=s;
              a.endTime=s+t;
              files.push_back(a);
       }
       
       while (files.size())
       {
              for(file a:files){
                     
                     int index=0;
                     if (a.startTime==0)
                     {
                            for (int j = 0; j < m;j++)//遍历打应机
                            {
                            //出队

                                   if (printers[j].front().endTime==0)
                                   {
                                          printers[j].pop();
                                   }
                                   
                                   
                            //入队
                                   if (printers[j].empty())
                                   {
                                          printers[j].push(a);//在空队列内插入
                                          continue;
                                   }else{
                                          index = printers[j].size()<printers[index].size()?j:index;//寻找最短队列
                                   }

                                   printers[index].push(a);//在最短队列内插入

                            }
                            files.remove(a);//从带打印队列中去除
                     }else{
                            a.startTime--;
                            a.endTime--;
                     }
              }
       }

       return 0;
}