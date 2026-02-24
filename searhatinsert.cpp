#include<stdio.h>
#include<vector>
using namespace std;
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int ans = nums.size();
        while (low<=high){
            int mid = (low+high)/2;
            if (nums[mid]>=target) {
            ans = mid;
            high = mid-1;
            }
            else {
            low = mid+1;
            }
        }
        return ans;
        
    }
    int main(){
        vector<int> nums = {1,3,5,6};
        int target = 5;
        int result = searchInsert(nums, target);
        printf("Element should be inserted at index: %d", result);
        return 0;
    }