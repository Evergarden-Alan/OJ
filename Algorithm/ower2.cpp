#include<iostream>

using namespace std;

int power2(int n){
       int pow = 1;
       int p = 2;
       while(n>0){
              if (n&1)
              {
                     pow *= p;                     
              }
              
              n>>=1;
              p *= p;
       }
       
       return pow;
}


int main(){
       cout<<power2(7)<<endl;
       return 0;
}