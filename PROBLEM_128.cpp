#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int longestconsectivesequence(vector<int>&nums) {
    int n=nums.size();
    int longest =0;
    int countcurr = 0;
    int lastsmaller =INT_MIN;
    sort(nums.begin(),nums.end());
    if(nums.size()==0) return 0;
    for (int i=0;i<n;i++)
    {
        if (nums[i]-1 == lastsmaller){
            countcurr=countcurr+1;
            lastsmaller = nums[i];
        }
        else if (nums[i]!=lastsmaller)
        {
            countcurr=1;
            lastsmaller=nums[i];

        }
        longest = max(longest,countcurr);
    }
    return longest;
}
int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = longestconsectivesequence(nums);
    cout << "Longest consecutive sequence length: " << result << endl;
    return 0;
}
