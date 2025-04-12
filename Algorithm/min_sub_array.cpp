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

int minSubArrayLen(int target, vector<int>& nums) {
    int min_len = INT32_MAX;
    int sum = 0;
    for(int i=0,j=0;i<nums.size();i++){
        sum += nums[i];
        while (sum>=target)//此处虽然是for套while，但其实是O(n)的复杂度，因为j只会增加，不会减少，所以j最多遍历n次，所以是O(2n)，即O(n)
        {
            min_len = min(min_len,i-j+1);
            sum -= nums[j++];
        }
    }
    return min_len==INT32_MAX?0:min_len;
}


int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    cout<<minSubArrayLen(target,nums)<<endl;
    return 0;
}