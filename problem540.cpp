#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])
                return nums[mid];

            if ((mid % 2 == 0 && nums[mid] == nums[mid+1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid-1])) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }

        return -1;
    }

    int main(){
        int n;
        cout<<"Enter the size of the array : ";
        cin>>n;
        vector<int>arr(n);
        cout<<"Enter the elements of the array : ";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<"The single non duplicate element is : "<<singleNonDuplicate(arr)<<endl;
    }
