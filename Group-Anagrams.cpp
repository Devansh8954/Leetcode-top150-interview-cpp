/*
49. Group Anagrams
Solved
Medium
Topics
Companies
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

//SOLUTION

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(int i=0; i<n; i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());

            mp[temp].push_back(strs[i]);
        }

        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
*/

class Solution {
public:
    string generate(string& word){
        int arr[26] = {0};
        for(char& ch : word){
            arr[ch - 'a']++;
        }
        string new_word = "";
        for(int i=0; i<26; i++){
            int freq = arr[i];
            if(freq>0){
                new_word += string(freq, i+'a');
            }
        }
        return new_word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(int i=0; i<n; i++){
            string word = strs[i];
            string new_word = generate(word);
            mp[new_word].push_back(word);
        }

        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};