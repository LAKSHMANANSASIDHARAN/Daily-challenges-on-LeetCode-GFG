/*3136. Valid Word
A word is considered valid if:
It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.
Return true if word is valid, otherwise, return false.
Notes:
'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.
 
Example 1:

Input: word = "234Adas"

Output: true

Explanation:

This word satisfies the conditions.

Example 2:

Input: word = "b3"

Output: false

Explanation:

The length of this word is fewer than 3, and does not have a vowel.

Example 3:

Input: word = "a3$e"

Output: false

Explanation:

This word contains a '$' character and does not have a consonant.*/
class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;

        bool vowel = false, consonant = false;

        for (char i : word) {
            if (!isalnum(i)) return false;

            if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' ||
                i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U') {
                vowel = true;
            }
            else if (isalpha(i)) {
                consonant = true;
            }
           
        }

        return vowel && consonant;
    }
};
