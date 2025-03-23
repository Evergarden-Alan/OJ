#include<iostream>
#include<vector>
#include <sstream>
#include <algorithm>

using namespace std;


int main(){
       int len;
       
       scanf("%d",&len);

       vector<int> list;

       string line;
       getline(cin, line);  // 读取整行输入
       stringstream ss(line);
       int value;
       while (ss >> value) {
              list.push_back(value);
       }
       
       sort(list.begin(),list.end());


       for (int i = 0; i < list.size(); i++)
       {
              printf("%d ",list[i]);
       }
       

       return 0;
}