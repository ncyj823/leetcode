#include<iostream>
using namespace std;

int sqrtofinteger(int n){
    if(n == 0) return 0;
    int ans = 1;
    int low = 1, high = n;
    while(low <= high){
        long long mid = (low + high) / 2;
        if(mid * mid == n){
            return mid;
        }
        else if(mid * mid < n){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Floor sqrt of " << n << " = " << sqrtofinteger(n) << endl;
    return 0;
}   