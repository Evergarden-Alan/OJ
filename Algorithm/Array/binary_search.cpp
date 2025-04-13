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

//版本1，区间左闭右闭
int binary_search_v1(vector<int> &nums, int target){
    int l=0,r=nums.size()-1;
    while(l<=r){//因为左闭右闭，所以l==r时有意义
        int mid = l+(r-l)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) l=mid+1;
        else r=mid-1;
    }
}

//版本2，区间左闭右开
int binary_search_v2(vector<int> &nums, int target){
    int l=0,r=nums.size();//因为左闭右开，所以r可以取数组长度
    while(l<r){//因为左闭右开，所以l==r没有意义
        int mid = l+(r-l)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) l=mid+1;
        else r=mid;
    }
}

int main(){
    cout<<5/2<<endl;
    return 0;
}