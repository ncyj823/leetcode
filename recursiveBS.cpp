#include<stdio.h>
using namespace std;
int binarysearch(int* arr, int low,int high,int target){
    if (low>high) return -1;
    int mid = (low+high)/2;
    if (arr[mid]==target) return mid;
    else if (target>arr[mid]) return binarysearch(arr, low, mid+1, target);
    else return binarysearch(arr, low, mid-1, target);
}

int main(){
    int arr[] = {3,4,6,7,9,12,16,17};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 12;
    int result = binarysearch(arr, 0, n-1, target);
    if (result != -1) printf("Element found at index: %d", result);
    else printf("Element not found in the array.");
    return 0;
}