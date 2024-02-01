/*
139. Word Break
Solved
Medium
Topics
Companies
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

class Solution {
public:
    unordered_set<string> st;
    int n;
    
    bool solve(string &s, int idx, vector<int>& t) {
        
        if(idx == n) {
            return true;
        }

        if(st.find(s.substr( idx , n - idx )) != st.end()) {
            return true;
        }
        
        if(t[idx] != -1)
            return t[idx];
        
        for(int l = 1; l<=n; l++) {
            
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solve(s, idx+l, t))
                return t[idx] = true;
            
        }
        
        return t[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        vector<int> t(n ,-1);
        
        for(string &word : wordDict) {
            st.insert(word);
        }
        
        return solve(s, 0, t);
    }
};
*/

class Solution {
public:
    bool solve(string s, vector<string>& wordDict) {
        unordered_set<string> st(begin(wordDict), end(wordDict));
        int n = s.length();
        vector<bool> t(n+1, false);
        /*
            t[i] = True;
            It means that for string of length i, its possible to break
            the word such that broken words are in wordDict
        */
        
        t[0] = true; //string of length 0 is always true
        
        for(int i = 1; i<=n; i++) {
            //we choose different point (j) to break
            for(int j = 0; j<i; j++) {
                string temp = s.substr(j, i-j);
                
                if(st.count(temp) && t[j]) {
                    /*
                        It means from s[j...i] is in wordDict
                        And, t[j] = true means s[0...j] could
                        also be broken correctly
                    */
                    
                    t[i] = true;
                    break;
                }
            }
        }
        return t[n]; //length n
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s, wordDict);
    }
};