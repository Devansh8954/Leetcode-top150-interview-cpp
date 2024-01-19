/*
6. Zigzag Conversion
Solved
Medium
Topics
Companies
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000


//SOLUTION
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans(numRows);
        if(numRows == 1)
            return s;
        bool flag =false;
        int i=0;
        for(auto ch: s){
            ans[i]+=ch;
            if(i == 0 || i == numRows-1){
                flag = !flag;
            }
            if(flag == true)
                i++;
            else
                i--;
        }
        string zigzag="";
        for(auto str: ans)
            zigzag+=str;
        return zigzag;
    }
};
*/

class Solution {
public:
    string convert(string s, int numsRows) {
        
        if(numsRows == 1 || numsRows >= s.size()){
            return s;
        }
        
        int n = s.size();
        string answer;
        int repetation = numsRows * 2 - 2;

        for(int i = 0; i < numsRows; i++){
            for(int j = 0; j + i < n; j += repetation){
                answer.push_back(s[i + j]);
                if(i != 0 && i != numsRows - 1 && j + repetation -i < n){
                    answer.push_back(s[j + repetation - i]);
                }
            }
        }

        return answer;
    }
};