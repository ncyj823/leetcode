#include<stdio.h>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = INT_MAX;
        while (low<=high){
            int mid = (low+high)/2;
            long long totalhrs = 0;

            for (int p : piles) {
                totalhrs += (p + mid - 1) / mid;
            }
            if (totalhrs <= h){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }   
    int main(){
        vector<int> piles = {3,6,7,11};
        int h = 8;
        int result = minEatingSpeed(piles, h);
        printf("%d\n", result);
        return 0;
    }