/*
290. Word Pattern
Solved
Easy
Topics
Companies
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,int> mp1;
        unordered_map<string,int> mp2;

        stringstream ss(s);
        string token;

        int countTokens = 0;
        int i=0;
        int n = pattern.size();

        while(ss >> token){
            countTokens++;
            if(i == n || mp1[pattern[i]] != mp2[token])
                return false;

            mp1[pattern[i]] = i+1;
            mp2[token] = i+1;
            i++;
        }
        if(countTokens != n || i != n)
            return false;

        return true;
    }
};