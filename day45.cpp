/*Total Characters in String After Transformations I
You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:
If the character is 'z', replace it with the string "ab".
Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
Return the length of the resulting string after exactly t transformations.
Since the answer may be very large, return it modulo 109 + 7.
Example 1:
Input: s = "abcyy", t = 2
Output: 7
Explanation:
First Transformation (t = 1):
'a' becomes 'b'
'b' becomes 'c'
'c' becomes 'd'
'y' becomes 'z'
'y' becomes 'z'
String after the first transformation: "bcdzz"
Second Transformation (t = 2):
'b' becomes 'c'
'c' becomes 'd'
'd' becomes 'e'
'z' becomes "ab"
'z' becomes "ab"
String after the second transformation: "cdeabab"
Final Length of the string: The string is "cdeabab", which has 7 characters.
Example 2:
Input: s = "azbk", t = 1
Output: 5
Explanation:
First Transformation (t = 1):
'a' becomes 'b'
'z' becomes "ab"
'b' becomes 'c'
'k' becomes 'l'
String after the first transformation: "babcl"
Final Length of the string: The string is "babcl", which has 5 characters.*/
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> hash(26, 0), temp(26, 0);
        const int mod = 1e9 + 7;

        for (char c : s) {
            hash[c - 'a']++;
        }

        for (int i = 0; i < t; i++) {
            for (int j = 0; j < 26; j++) {
                if (j == 25) { 
                    temp[0] = (temp[0] + hash[25]) % mod; 
                    temp[1] = (temp[1] + hash[25]) % mod; 
                } else {
                    temp[j + 1] = (temp[j + 1] + hash[j]) % mod;
                }
            }
            hash = temp;
            fill(temp.begin(), temp.end(), 0);
        }

        int res = 0;
        for (int count : hash) {
            res = (res + count) % mod;
        }
        return res;
    }
};
