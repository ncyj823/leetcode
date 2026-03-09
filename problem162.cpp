#include<iostream>
#include<vector>
using namespace std;
int findPeakElement(vector<int>& nums) {
        int high= nums.size()-1;
        int low = 0;
        while (low < high)
        {
            int mid = low + (high-low)/2;

            if (nums[mid] < nums[mid+1]){
                low = mid + 1;
            }
            else
            {
                high = mid;

            }
            
        }
    return low;
        
}

int main(){
    vector<int> nums = {1,2,3,1};
    cout<<findPeakElement(nums);
}