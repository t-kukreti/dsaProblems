#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// max your profit by choosing a single day to buy one stock & choosing a different day to sell that stock in future


int maxProfit(vector<int> &prices){
    if(prices.size() == 1) return 0;

    int lowestPrice = prices[0];
    int maxProfit = 0, profit = 0;

    for(int i=1; i<prices.size(); i++){
        // lowest price seen so far
        if(lowestPrice > prices[i]){
            lowestPrice = prices[i];
        }

        int currentPrice = prices[i];
        // calculate profit
        if(currentPrice > lowestPrice){
            profit = currentPrice - lowestPrice;
            if(profit > maxProfit) maxProfit = profit;
        }

    }

    return maxProfit;


}
int main(){
    // price of a stock in a particlar ith day
    vector<int> prices = {2,4,1};
    cout << maxProfit(prices) << endl;
    return 0;
}