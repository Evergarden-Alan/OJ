#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <numeric>
#include <limits>
// 快速输入输出
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;


int version1(){//超时，因为cout和cin效率太低
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> temp(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
        if (i!=0)
        {
            temp[i] = temp[i-1]+nums[i];    
        }else{
            temp[0] = nums[0];
        }
    }
    int a,b;
    while (cin>>a>>b)
    {
        if (a==0)
        {
            cout<<temp[b]<<endl;
        }else{
            cout<<temp[b]-temp[a-1]<<endl;
        }
        
    }
    

    return 0;
}


int main(){//全部转换为scanf和printf后AC
    int n;
    scanf("%d",&n);
    vector<int> nums(n);
    vector<int> temp(n,0);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
        if (i!=0)
        {
            temp[i] = temp[i-1]+nums[i];    
        }else{
            temp[0] = nums[0];
        }
    }
    int a,b;
    while (~scanf("%d%d",&a,&b))
    {
        int sum;
        if (a==0)
        {
            sum = temp[b];
        }else{
            sum = temp[b]-temp[a-1];
        }
        printf("%d\n",sum);
    }
    

    return 0;
   
}