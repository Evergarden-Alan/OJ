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


int find_left(vector<int>& nums,int target){
    int lo = 0,hi = nums.size()-1;
    int left_border=-2;
    while(lo<=hi){
        int mi = (hi-lo)/2+lo;
        if(nums[mi]>=target){
            hi = mi-1;
            left_border = hi;
        }else{
            lo = mi+1;
        }
    }
return left_border;
}


int find_right(vector<int>& nums,int target){
    int lo = 0,hi = nums.size()-1;
    int right_border=-2;
    while(lo<=hi){
        int mi = (hi-lo)/2+lo;
        if(nums[mi]>target){
            hi = mi-1;
        }else{
            lo = mi+1;
            right_border = lo;
            
    }
    }
return right_border;
}

int getRightBorder(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
    int rightBorder = -2; // 记录一下rightBorder没有被赋值的情况
    while (left <= right) { // 当left==right，区间[left, right]依然有效
        int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
        if (nums[middle] > target) {
            right = middle - 1; // target 在左区间，所以[left, middle - 1]
        } else { // 当nums[middle] == target的时候，更新left，这样才能得到target的右边界
            left = middle + 1;
            rightBorder = left;
        }
    }
    return rightBorder;
}


vector<int> searchRange(vector<int>& nums, int target) {
        
        int left_border = find_left(nums,target);
        int right_border = find_right(nums,target);
        if(left_border == -2 || right_border == -2){
            return {-1,-1};    
        }else if((right_border - left_border)>1){
            return {left_border+1,right_border-1};
        }
        return {-1,-1};
    }



int main(){

    vector<int> nums = {2,2};
    int target = 3;
    vector<int> ans = searchRange(nums,target);
    cout<<ans[0]<<","<<ans[1]<<endl;
    return 0;
}