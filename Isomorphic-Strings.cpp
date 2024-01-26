/*
205. Isomorphic Strings
Solved
Easy
Topics
Companies
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

/*
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp1, mp2;
        if(s.size() != t.size()) return false;

        for(int i= 0; i< s.size(); i++){
            if(mp1.find(s[i]) != mp1.end()){
                if(mp1[s[i]] != t[i])
                    return false;
            } 
            else if(mp2.find(t[i]) != mp2.end()){
                if(mp2[t[i]] != s[i])
                    return false;
            }
            else {
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }
        }
        return true;
    }
};
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector <int> s_map (128, -1);
        vector <int> t_map (128, -1);
        if(s.size()== t.size()){
            for(int i = 0 ; i<s.size(); i++){
                if(s_map[s[i]] != t_map[t[i]]) return false;
                s_map[s[i]] = t_map[t[i]] = i;
            }
            return true;
        }
        else return false;

    }
};