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

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> temp = nums;
    int k = nums.size()-1;
    for(int i=0,j=nums.size()-1;i<=j;){
        int low_p = nums[i]*nums[i];
        int high_p = nums[j]*nums[j];
        if(low_p>high_p){
            temp[k] = low_p;
            i++;
            k--;
        }else{
            temp[k] = high_p;
            j--;
            k--;
        }
    }

    return temp;
}


int main(){
    vector<int> nums = {-4,-1,0,3,10};
    sortedSquares(nums);
    return 0;
}