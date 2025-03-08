/*Minimum Recolors to Get K Consecutive Black Blocks
You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.
You are also given an integer k, which is the desired number of consecutive black blocks.
In one operation, you can recolor a white block such that it becomes a black block.
Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.
Example 1:
Input: blocks = "WBBWWBBWBW", k = 7
Output: 3
Explanation:
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
so that blocks = "BBBBBBBWBW". 
It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
Therefore, we return 3.
Example 2:
Input: blocks = "WBWBBBW", k = 2
Output: 0
Explanation:
No changes need to be made, since 2 consecutive black blocks already exist.
Therefore, we return 0.*/
class Solution {
public:
    int consecutive(string blocks, int k) {
        int con = 0;
        int maxi = 0;
        if (blocks[0] == 'B') {
            con++;
        }
        int i = 1;
        while (i < blocks.size()) {
            if (blocks[i] == 'B') {
                if (blocks[i - 1] == 'B') {
                    con++;
                } else {
                    con = 1;
                }
            } else {
                maxi = max(maxi, con);
                con = 0;
            }
            i++;
        }
        return maxi;
    }

public:
    int minimumRecolors(string blocks, int k) {
        int tempp = consecutive(blocks, k);
        if (tempp == k) {
            return 0;
        }
        int i = 0;
        int j = k - 1;
        int count, mini = k + 1;
        while (j < blocks.size()) {
            int temp = i;
            count = 0;
            while (temp <= j) {
                if (blocks[temp] == 'W') {
                    count++;
                }
                temp++;
            }
            mini = min(mini, count);
            i++;
            j++;
        }
        return mini;
    }
};
