/*Number of Substrings Containing All Three Characters
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.
Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:
Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:
Input: s = "abc"
Output: 1*/
class Solution {
    
public:
    int numberOfSubstrings(string s) {
        int i = 0, j = 0, count = 0;
    unordered_map<char, int> freq;

    while (j < s.size()) {
        freq[s[j]]++; 

        while (freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0) {  
            count += (s.size() - j);  
            freq[s[i]]--; 
            i++;
        }
        j++;  
    }
    
  
        return count;
    }
};
