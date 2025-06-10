/*Maximum Difference Between Even and Odd Frequency I
You are given a string s consisting of lowercase English letters.
Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:
a1 has an odd frequency in the string.
a2 has an even frequency in the string.
Return this maximum difference.
Example 1:
Input: s = "aaaaabbc"
Output: 3
Explanation:
The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
The maximum difference is 5 - 2 = 3.
Example 2:
Input: s = "abcabcab"
Output: 1
Explanation:
The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
The maximum difference is 3 - 2 = 1.*/
class Solution {
public:
    int maxDifference(string s) {
        vector<int>hash(26,0);
        for(auto i:s){
            hash[i-'a']++;
        }
        int  maxodd=INT_MIN,mineven=INT_MAX;
        for(auto i:hash){
            if(i==0) continue;
            if(i%2!=0) {
            maxodd=max(maxodd,i);
            }
            else {
             mineven=min(mineven,i);
            }
        }
        int res=maxodd-mineven;
        return res;
        
    }
};
