/*
151. Reverse Words in a String
Solved
Medium
Topics
Companies
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

SOLUTIIONS
class Solution {
public:
    string reverseWords(string str) {
        string words,result;
        stack<string>st;
        stringstream s(str);
        while(s>>words){
            st.push(words);
        }

        while(!st.empty()){
            result+=st.top();
            st.pop();
            if(!st.empty()){
            result+=" ";
            }
        }
        return result;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        stack<string> st;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch == ' '){
                if(temp!=""){
                    st.push(temp);
                }
                temp="";
            }
            else {
                temp+=ch;
            }
        }
        if(temp!=""){
            st.push(temp);
        }
        string ans="";
        while(!st.empty()){
            ans+=(st.top()+" ");
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};
*/

class Solution{
public: 
    
    string reverseWords(string s) 
    {
        string tmp="", ans="";
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            if(ch==' ')
            {
                if(tmp!="")
                    ans = tmp + " " + ans;
                tmp = "";        
            }
            else 
                tmp += ch;
        }
        
        if(tmp!="")
            ans = tmp + " " + ans;
        ans.pop_back();
        
        return ans;      
    }
};