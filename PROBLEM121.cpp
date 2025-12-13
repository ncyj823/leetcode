#include<iostream>
#include<vector>
using namespace std;
vector<int> maxProfit(vector<int>& prices) {
    int mini = prices[0];
    int maxprofit =0;
    int n = prices.size();
    for(int i = 0 ; i<n ; i++)
    {
        int cost = prices[i]-mini;
        maxprofit= max(maxprofit , cost);
        mini= min(mini,prices[i]);
    }
    return {maxprofit};
}
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    vector<int> result = maxProfit(prices);
    cout << "Maximum Profit: " << result[0] << endl;
    return 0;
}
