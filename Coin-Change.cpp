/*
322. Coin Change
Solved
Medium
Topics
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

/*SOLUTION
class Solution {
public:
    int solve(vector<int>& c, int x,vector<int>& dp){
    if(x == 0) return 0;

    if(x<0) return INT_MAX;

    if(dp[x] != -1) return dp[x];

    int mini = INT_MAX;
    for(int i=0;i<c.size();i++){
        int ans = solve(c, x-c[i],dp);
        if(ans != INT_MAX){
            mini = min(mini, 1+ans);
        }
    }

    return dp[x] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1 , -1);
        int ans =  solve(coins, amount, dp);
        if(ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};
*/

class Solution {
public:
    int solve(vector<int>& c, int x){
    vector<int> dp(x+1 , INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=x; i++){
        for(int j=0; j<c.size();j++){
            if(i-c[j] >= 0 && dp[i-c[j]] != INT_MAX){
                dp[i] = min(dp[i], 1+dp[i-c[j]]);
            }
            
        }

    }
    if(dp[x] == INT_MAX){
        return -1;
    }
    return dp[x];
    }

    

    int coinChange(vector<int>& coins, int amount) {
        return solve(coins, amount);
    }
};