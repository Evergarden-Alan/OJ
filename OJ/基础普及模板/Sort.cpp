#include<iostream>
#include<vector>

using namespace std;


int main(){
       int len;
       
       scanf("%d",&len);

       vector<int> list;
       int value;
       while (cin>>value)
       {
              list.push_back(value);
       }
       
       sort(list.begin(),list.end());


       for (int i = 0; i < list.size(); i++)
       {
              printf("%d ",list[i]);
       }
       

       return 0;
}