/* Count the Number of Fair Pairs
Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
A pair (i, j) is fair if:
0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
Example 1:
Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
Example 2:
Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).*/
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        int l = 0, r = n;
        long long count_two = 0;
        long long count = 0;
        while (l < r) {
            long long sum = nums[l] + nums[r];
            if (sum < lower) {
                                
                l++;
                
            } else if (sum > upper) {
               
                r--;
                
            } else {
                count_two = 0;
                count += r - l;
                int k = l + 1;
                while (k < r) {
                    long long sum_two = nums[l] + nums[k];
                    if (sum_two < lower) {
                        count_two++;
                        k++;
                    } else {
                        break;
                    }
                }
                count = count - count_two;
                l++;
               
            }
        }
        return count;
    }
};
