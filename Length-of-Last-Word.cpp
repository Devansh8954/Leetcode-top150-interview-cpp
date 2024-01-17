/*
58. Length of Last Word
Solved
Easy
Topics
Companies
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/

/*
SOLUTIONS
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        while(ss>>word){}
        return word.length();
    }
};
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length()-1,result=0;
        while(n>=0){
            if(s[n] != ' '){
                result++;
            }
            else if(result>0){
                return result;
            }
            n--;
        }
        return result;
    }
};