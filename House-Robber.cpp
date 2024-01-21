/*
198. House Robber
Solved
Medium
Topics
Companies
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

/*SOLUTION 1
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int n){
        if(i>=n) return 0;

        if(t[i] != -1) return t[i];

        int steal = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        return t[i] = max(steal,skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, n);
    }
};
*/
/*SOLUTION 2

class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];

        vector<int> t(n+1, 0);

        t[0] = 0;
        t[1] = nums[0];
        for(int i=2;i<=n;i++){
            int steal = nums[i-1] + t[i-2];
            int skip = t[i-1];

            t[i] = max(steal,skip);
        }
        return t[n];
    }
};

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];

        int prevprev = 0,temp=0;
        int prev = nums[0];
        for(int i=2;i<=n;i++){
            int steal = nums[i-1] + prevprev;
            int skip = prev;

            temp = max(steal,skip);
            prevprev = prev;
            prev = temp;
        }
        return prev;
    }
};