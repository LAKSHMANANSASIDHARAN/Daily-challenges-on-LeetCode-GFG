/*1957. Delete Characters to Make Fancy String
A fancy string is a string where no three consecutive characters are equal.
Given a string s, delete the minimum possible number of characters from s to make it fancy.
Return the final string after the deletion. It can be shown that the answer will always be unique.
Example 1:
Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
Example 2:
Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
Example 3:
Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".*/
class Solution {
public:
    string makeFancyString(string s) {
        string ans=""; 
        ans+=s[0];
        int count=1;
        int i=1;
       while(i<s.size()){
        if(s[i]==s[i-1] && count<2){
            ans+=s[i];
            count++;
            i++;
        }
        else if(count==2 && s[i]==s[i-1]){
          i++;
        }
        else{
            count=1;
            ans+=s[i];
            i++;
        }
       }
         return ans;
    }
};
