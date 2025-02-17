/*Letter Tile Possibilities
You have n  tiles, where each tile has one letter tiles[i] printed on it.
Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.
Example 1:
Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:
Input: tiles = "AAABBC"
Output: 188
Example 3:
Input: tiles = "V"
Output: 1*/
class Solution {
    int buildString(vector<int>&freq){
        int ways=0;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                freq[i]--;
                ways+=1+buildString(freq);
                  freq[i]++;
            }
        }
        return ways;
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int>freq(26,0);// according to the Constraint there are always only captial lettter not small or number.
        for(char c: tiles){// so can use vector of size 26 and assign that all as 0.
            freq[c-'A']++;

        }
        return buildString(freq);
    }
};
