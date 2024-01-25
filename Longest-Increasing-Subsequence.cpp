/*
300. Longest Increasing Subsequence
Solved
Medium
Topics
Companies
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

/*SOLUTIONS
class Solution {
public:
    int solve(vector<int>& a, int curr, int pre, int n, vector<vector<int>>& dp){
        if(curr == n) return 0; 

        if(pre != -1 && dp[curr][pre] != -1){
            return dp[curr][pre];
        }

        int include=0;
        if(pre == -1 || a[pre]<a[curr]){
            include = 1 + solve(a, curr+1, curr, n, dp);
        }
        
        int exclude = solve(a, curr+1, pre, n, dp);

        if(pre != -1){
            dp[curr][pre] = max(include,exclude);
        }
        return max(include,exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(nums, 0, -1, n, dp);
    }
};
*/