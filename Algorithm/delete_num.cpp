#include<iostream>
#include<vector>


using namespace std;
int removeElement(vector<int>& nums, int val) {
       int length = nums.size();
       int k=0;
       for(int i=0;i<length-k;i++){
           if(nums[i]==val){
               k+=1;
               for(int j=i;j<length-k;j++){
                   nums[j]=nums[j+1];
               }
               i-=1;
           }
       }
       return k;
   }

//双指针版本O(n)
int removeElement_double_point(vector<int>& nums, int val) {
       int slow=0;
       for(int fast=0;fast<nums.size();fast++){
           if(nums[fast]!=val){
               nums[slow] = nums[fast];
               slow++;
           }
       }
       return slow;
   }


int main(){
       vector<int> nums = {0,1,2,2,3,0,4,2};
       // removeElement(nums,2);
       removeElement_double_point(nums,2);
}
