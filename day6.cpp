/* Shortest Common Supersequence 
Given two strings str1 and str2, return the  shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.
Example 1:
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"*/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        vector<vector<int>> lcs(m + 1, vector<int>(n + 1, 0));

      
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                } else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }

        int i = m, j = n;
        string result = "";
        
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                i--, j--;
            } else if (lcs[i - 1][j] > lcs[i][j - 1]) {
                result += str1[i - 1];
                i--;
            } else {
                result += str2[j - 1];
                j--;
            }
        }

        while (i > 0) result += str1[--i];
        while (j > 0) result += str2[--j];

        reverse(result.begin(), result.end());
        return result;
    }
};
