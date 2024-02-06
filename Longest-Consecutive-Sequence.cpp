/*
128. Longest Consecutive Sequence
Solved
Medium
Topics
Companies
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109

//SOLUTION
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;

        sort(nums.begin(),nums.end());

        int ans=0;
        int temp=1;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1] + 1){
                    temp++;
                }
                else {
                    ans = max(temp,ans);
                    temp=1;
                }
        }}
        return max(ans,temp);
    }
};
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        unordered_map<int,bool> mp;
        int ans = 0;
        for(int num : nums){
            mp[num] = false;
        }

        for(int num: nums){
            int currentlength = 1;

            int nextNum = num+1;
            while(mp.find(nextNum) != mp.end() && mp[nextNum] == false){
                currentlength++;
                mp[nextNum] = true;
                nextNum++;
            }

            int prevNum = num-1;
            while(mp.find(prevNum) != mp.end() && mp[prevNum] == false){
                currentlength++;
                mp[prevNum] = true;
                prevNum--;
            }

            ans = max(ans,currentlength);
        }

        return ans;
    }
};