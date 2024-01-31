/*
224. Basic Calculator
Solved
Hard
Topics
Companies
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.

//SOLUTION
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = s.length();
        int num=0;
        int result=0;
        int sign=1;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                num = num*10 + (s[i] - '0');
            }
            else if(s[i] == '+'){
                result += (num*sign);
                num = 0;
                sign = 1;
            }
            else if(s[i] == '-'){
                result += (num*sign);
                num = 0;
                sign = -1;
            }
            else if(s[i] == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                num = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                result += (num*sign);
                num = 0;

                int stack_sign = st.top();
                st.pop();
                int last_result = st.top();
                st.pop();
                result *= stack_sign;
                result += last_result;
            }
        }
        result += (num*sign);
        return result;
    }
};
*/

class Solution {
public:
    int calculate(string s) {
        int currSum = 0, sign = 1;
        stack<int> st;
        
        for (int i = 0 ; i < s.size() ; ++i) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num *= 10;
                    num += s[i] - '0';
                    ++i;
                }

                --i;
                currSum += (sign * num);
            }
            else if (s[i] == '-' || s[i] == '+') {
                sign = (s[i] == '-') ? -1 : 1;
            }
            else if (s[i] == '(') {
                st.push(currSum);
                st.push(sign);
                currSum = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                int prevSign = st.top(); st.pop();
                int prevSum = st.top(); st.pop();
                currSum = (prevSum + prevSign * currSum);
            }
        }

        return currSum;
    }
};