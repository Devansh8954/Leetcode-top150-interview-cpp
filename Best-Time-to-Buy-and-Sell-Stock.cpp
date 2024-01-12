/*
121. Best Time to Buy and Sell Stock
Solved
Easy
Topics
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

//SOLUTION

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();

        if(size==0){
            return 0;
        }
        int l=0, r=1, maxProfit=0, profit;

        while(r<size){
            if(prices[l]<prices[r]){
                profit = prices[r] - prices[l];
                maxProfit = max(profit, maxProfit);
            }
            else {
                l=r;
            }
            r++;
        }
        if(maxProfit>0){
            return maxProfit;
        }
        return 0;
    }
};
*/

//SOLUTION
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int maxprof = 0;

        for(int i=1;i<prices.size();i++){
            maxprof = max(maxprof,prices[i]-min_price);
            min_price = min(prices[i],min_price);
        }

        return maxprof;
    }
};