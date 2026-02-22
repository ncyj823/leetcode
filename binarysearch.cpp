#include<iostream>
using namespace std;
int binarysearch(int arr[],int n ,int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if (arr[mid]==target)return mid;
        else if (target >arr[mid]) low = mid+1;
        else high = mid-1;
    }
    return -1;
}
int main(){
    int arr[] = {3,4,6,7,9,12,16,17};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 12;
    int result = binarysearch(arr,n,target);
    if (result != -1) cout<<"Element found at index: "<<result;
    else cout<<"Element not found in the array.";
    return 0;
}