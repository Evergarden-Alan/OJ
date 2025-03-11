#include<iostream>

using namespace std;

int main(){

       int x,y,p,q,maxR;
       cin>>x>>y>>p>>q;

       int paddingX,paddingY;

       //水杯圆心到边界的距离
       /*
              0<p<x<=100;0<q<y<100;即x-p；y-q；不存在负数情况
              到左边界距离为p，右边界距离为x-p
              到下界距离为q，上界距离为y-q
       */
       paddingX = x-p>p?p:x-p;
       paddingY = y-q>q?q:y-q;

       cout<<(paddingX>paddingY?paddingY:paddingX);       

       return 0;
}