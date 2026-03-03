#include<iostream>
#include<vector>
using namespace std;
int firstoccurance(vector<int>&arr,int n,int x)
    {
     int low =0 , high = n-1;
     int first = -1;
     while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==x)
        {
            first=mid,high=mid-1;
        }
        else if (arr[mid]<x){
            low=mid+1;
        }
        else {
            high = mid- 1;
        }
        
     }
     return first;
    }
    int lastoccurance(vector<int>&arr,int n , int x)
    {
        int low =0, high = n-1;
        int last = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==x){
                last=mid,low=mid+1;
            }
            else if (arr[mid]<x){
                low = mid+1;
            }
            else {
                high = mid - 1;
            }
            return last;
        }
    }
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();

        int first = firstoccurance(nums, n, target);
        int last = lastoccurance(nums, n, target);

        return {first, last};
    }
    int main(){
        int n,x;
        cout<<"Enter the size of the array : ";
        cin>>n;
        vector<int>arr(n);
        cout<<"Enter the elements of the array : ";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<"Enter the element to find : ";
        cin>>x;
        int first = firstoccurance(arr,n,x);
        int last = lastoccurance(arr,n,x);
        if(first==-1 || last==-1){
            cout<<"Element not found in the array."<<endl;
        }
        else {
            cout<<"First occurance of "<<x<<" is at index : "<<first<<endl;
            cout<<"Last occurance of "<<x<<" is at index : "<<last<<endl;
        }
    }