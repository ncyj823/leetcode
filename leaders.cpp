#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<int> leaderinArray(const vector<int> &nums) {
    vector<int> ans;
    int maxi = INT_MIN;
    int n = static_cast<int>(nums.size());
    for (int i = n - 1; i >= 0; --i) {
        if (nums[i] > maxi) {
            ans.push_back(nums[i]);
            maxi = nums[i];
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> nums = {10, 4, 22, 1, 3, 6};
    vector<int> result = leaderinArray(nums);
    cout << "Leaders in the array: ";
    for (int x : result) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}