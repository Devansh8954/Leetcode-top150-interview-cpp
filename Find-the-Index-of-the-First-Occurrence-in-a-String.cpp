/*
28. Find the Index of the First Occurrence in a String
Solved
Easy
Topics
Companies
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

//SOLUTION
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int index=0;
        for(index=0;index<haystack.length();index++ )
        {
            if(haystack[index]==needle[0])
            {
                int i=index;
                int j=0;
                while(j<needle.length())
                {
                    if(haystack[i]==needle[j])
                    {
                        i++;
                        j++;
                    }
                    else
                        break;
                }
                if(j==needle.length())
                    return index;
            }
        }
        return -1;
    }
};