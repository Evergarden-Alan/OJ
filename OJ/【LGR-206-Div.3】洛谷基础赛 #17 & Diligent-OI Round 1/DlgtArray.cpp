#include<iostream>

using namespace std;

int main(){
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

       /*
              sequence start with index 1,，ai==0:1,so
              while:PI(l->r)==1,Sigma(l->r)(a)==r-l+1;
                     so if l-r+1!=k+1 
                     at least one ai==0;

              while PI(l->r)==0,Sigma(l->)(a)<r-l+1;
                     so if l-r<k,none result
                     if l-r>k,maybe have a result

       */

       int result = -1;
       for (int i = 0; i < q; i++)
       {
              if ( qList[i][1]-qList[i][0] != qList[i][2])//不满足最简情况
              {
                     if (qList[i][1]-qList[i][0]<qList[i][2])//none result
                     {
                            break;
                     }
                     else
                     {
                            result = qList[i][2]-(qList[i][1]-qList[i][0]);
                            break;
                     }
                     
              }
              else{
                     //count opration number of 0->1,
                     sort(a,a+n);
                     for (int i = 0; i < n; i++)
                     {
                            if (a[i]==1)
                            {
                                   break;
                            }
                            
                     }
                     result = i;
              }
       }
       cout<<result;
       

       return 0;
}