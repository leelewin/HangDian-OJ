#include<iostream>
using namespace std;

int majorityElement(int* nums, int numsSize){
    if(nums == NULL || numsSize == 0) return -1;
    if(numsSize == 1) return nums[0];
    int mid;
    mid = numsSize / 2;
    int left, right;
    left = majorityElement(nums, mid);
    right = majorityElement(nums+mid, numsSize-mid);
    if(left == right) return left;        //左右众数一样
    int left_count = 0, right_count = 0;
    for(int i=0; i<numsSize; i++){        //左右众数不一样，统计相应的出现次数
        if(nums[i] == left) left_count++;
        if(nums[i] == right) right_count++;
    }
    if(left_count == right_count)      //fix: [2,3]情况下失败
        return -1;
    else
        return (left_count > right_count)?left:right;
}

int main(void){



    return 0;
}