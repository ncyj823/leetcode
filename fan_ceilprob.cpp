//floor:largest no. in an array <= x
//ceil: smallest no. in an array >=x
//case of uppper and lower bound
#include <iostream>
using namespace std;

int floor(int arr[], int n, int x)
{
    int ans = -1;
    int low = 0;
    int high = n - 1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]<=x){
            ans=arr[mid];
            low = mid+1;  // search for larger value in right half
        }
        else {
            high= mid-1;
        }
    }
    return ans;
}

int ceil(int arr[], int n, int x)
{
    int ans = -1;
    int low = 0;
    int high = n - 1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>=x){
            ans=arr[mid];
            high= mid-1;  // search for smaller value in left half
        }
        else {
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {10,20,25,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x;
    cin>>x;
    cout<<"Floor: "<<floor(arr,n,x)<<endl;
    cout<<"Ceil: "<<ceil(arr,n,x)<<endl;
}
