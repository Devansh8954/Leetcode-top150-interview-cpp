/*
242. Valid Anagram
Solved
Easy
Topics
Companies
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        int n = s.size();
        int m = t.size();
        if(m != n){
            return false;
        }
        for(int i=0; i<s.size(); i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        if(mp1 != mp2){
            return false;
        }

        return true;
    }
};
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};

        for(char c : s)
            count[c - 'a']++;

        for(char c : t)
            count[c - 'a']--;

        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }

        return true; 
    }
};