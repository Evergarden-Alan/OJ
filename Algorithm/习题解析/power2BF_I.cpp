
#include<iostream>
using namespace std;
int power2BF_I(int n,int pow){
       if (n==1)
       {
              return pow;
       }else{
              return power2BF_I(--n,pow<<=1);
       }
}

int power2BF_I_Book(int n){
       return (1>n)?1:power2BF_I_Book(n-1)<<1;
}


int main(){
       int n=8;
       int pow = 2;

       // cout<<power2BF_I(n,pow)<<endl;
       cout<<power2BF_I_Book(n)<<endl;

       return 0;
}