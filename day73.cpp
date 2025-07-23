/*1717. Maximum Score From Removing Substrings
You are given a string s and two integers x and y. You can perform two types of operations any number of times.
Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.
Example 1:
Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:
Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 */
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char>st;
        int ans=0;
        char temp_1,temp_2;
        if(x>y) temp_1='b',temp_2='a';
        else temp_1='a',temp_2='b';
        int maxi=max(x,y),mini=min(x,y);
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i]==temp_1 && st.top()==temp_2){
              ans+=maxi;
              st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
      
              string rem;
        while(!st.empty()){
            rem += st.top();
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        for(char c : rem){
            if(!st.empty() && c==temp_2 && st.top()==temp_1){
                ans += mini;
                st.pop();
            } else {
                st.push(c);
            }
        }

        return ans;
    }
};
