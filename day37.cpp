/* Count Largest Group
You are given an integer n.
Each number from 1 to n is grouped according to the sum of its digits.
Return the number of groups that have the largest size.
Example 1:
Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
There are 4 groups with largest size.
Example 2:
Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.*/
class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> hash(37, 0);
        int maxi = 0;
        for (int i = n; i >= 1; i--) {
            int temp = i;
            int sum = 0;
            while (temp) {
                sum += temp % 10;
                temp = temp / 10;
            }
            hash[sum]++;
            maxi = max(maxi, hash[sum]);
        }
        int count = 0;
        for (int i = 1; i <= 36; i++) {
            if (hash[i] == maxi) {
                count++;
            }
        }
        return count;
    }
};
