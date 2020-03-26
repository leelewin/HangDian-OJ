#include<iostream>
using namespace std;

int maxSumArray(int *nums, int left, int right){
    if(right == left){
        if(nums[right] > 0)
            return nums[right];
        else
            return 0;
    }
    else{
        int s1 = 0, s2 = 0;
        int mid;
        int sum1, sum2, sum3;

        mid = (left + right) / 2;
        sum1 = maxSumArray(nums, 0, mid);
        sum2 = maxSumArray(nums, mid + 1, right);
        s1 = nums[mid];
        for(int i = mid - 1; i>=0; i--){
            if(s1 + nums[i] < s1)
                break;
            s1 += nums[i];
            
        }
        for(int i = mid + 1; i <= right; i++){
            if(s2 + nums[i] > s2)
                s2 += nums[i];
            else{
                break;
            }
        }
        sum3 = s1 + s2;
        return max(max(sum1, sum2), sum3);

    }
}
int main(void){

    int a[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ret = maxSumArray(a, 0, 8);
    cout << ret << endl;

}







