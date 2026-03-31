#include<stdio.h>
#include<vector>
using namespace std;
int findKthpos(vector<int>& arr , int k){
    int low =0;
    int high = arr.size();

    while(low<high){
        int mid = (low + high)/2;
        int missing = arr[mid] -arr[mid+1];

        if (missing < k){
            low = mid + 1;

        }
        else 
        {
            high = mid;
        }
        
    }
    return low+k;
}

int main (){
    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    printf("%d",findKthpos(arr,k));
}