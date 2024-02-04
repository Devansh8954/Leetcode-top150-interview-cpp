/*
30. Substring with Concatenation of All Words
Solved
Hard
Topics
Companies
You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.

 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Since words.length == 2 and words[i].length == 3, the concatenated substring has to be of length 6.
The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
The output order does not matter. Returning [9,0] is fine too.
Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Explanation: Since words.length == 4 and words[i].length == 4, the concatenated substring has to be of length 16.
There is no substring of length 16 in s that is equal to the concatenation of any permutation of words.
We return an empty array.
Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
Explanation: Since words.length == 3 and words[i].length == 3, the concatenated substring has to be of length 9.
The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"] which is a permutation of words.
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"] which is a permutation of words.
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"] which is a permutation of words.
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = words[0].size();
        int n = words.size();
        int tl = m*n;
        unordered_map<string,int> mp1;
        vector<int> ans;
        
        for(string& word : words){
            mp1[word]++;
        }

        if(tl>s.size()){
            return ans;
        }

        for(int i=0; i<m; i++){
            unordered_map<string,int> mp2;
            int left = i;
            for(int j=i; j<=s.size()-m; j+=m){
                string temp = s.substr(j,m);

                if(mp1.find(temp) != mp1.end()){
                    mp2[temp]++;

                    while(mp2[temp]>mp1[temp]){
                    mp2[s.substr(left,m)]--;
                    left+=m;
                }
                if(j-left+m == tl){
                    ans.push_back(left);
                    mp2[s.substr(left,m)]--;
                    left+=m;
                }
                }
                else {
                    mp2.clear();
                    left = j+m;
                }
            }
        }
        return ans;
    }
};