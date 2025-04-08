/*Minimum Number of Operations to Make Elements in Array Distinct
You are given an integer array nums. You need to ensure that the elements in the array are distinct. To achieve this, you can perform the following operation any number of times:
Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining elements.
Note that an empty array is considered to have distinct elements. Return the minimum number of operations needed to make the elements in the array distinct.
Example 1:
Input: nums = [1,2,3,4,2,3,3,5,7]
Output: 2
Explanation:
In the first operation, the first 3 elements are removed, resulting in the array [4, 2, 3, 3, 5, 7].
In the second operation, the next 3 elements are removed, resulting in the array [3, 5, 7], which has distinct elements.
Therefore, the answer is 2.
Example 2:
Input: nums = [4,5,6,4,4]
Output: 2
Explanation:
In the first operation, the first 3 elements are removed, resulting in the array [4, 4].
In the second operation, all remaining elements are removed, resulting in an empty array.
Therefore, the answer is 2.
Example 3:
Input: nums = [6,7,8,9]
Output: 0
Explanation:
The array already contains distinct elements. Therefore, the answer is 0.*/
class Solution {
    int find_operation(int num) {
        int bal = 0, count = 0;
        while (num >= 3) {
            num = num - 3;
            count++;
        }

        return (num != 0) ? count + 1 : count;
    }

public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;
        int ans=0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (s.find(nums[i]) != s.end()) {
                 ans = find_operation( i+1);
                break;
            }
            s.insert(nums[i]);
        }
       return ans;
    }
};
/* Excel Sheet Column Title
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
Example 1:
Input: columnNumber = 1
Output: "A"
Example 2:
Input: columnNumber = 28
Output: "AB"
Example 3:
Input: columnNumber = 701
Output: "ZY"*/
class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<char> hash(26);
        int val = 'A';
        for (int i = 0; i < 26; i++) {
            hash[i] = val + i;
        }
        string ans;
        while (columnNumber > 0) {
            columnNumber--; 
            int temp = columnNumber % 26;
            ans += hash[temp];
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
/*Longest Palindrome
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome.
Example 1:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.*/
class Solution {
   static bool compare(const pair<char, int>& a, const pair<char, int>& b) {
    return a.second > b.second;
}

public:
    int longestPalindrome(string s) {
        vector<pair<char, int>> mp(52, {'0', 0});
      for (char it : s) {
        int idx;
        if (islower(it)) idx = it - 'a';
        else idx = it - 'A' + 26;

        if (mp[idx].second != 0) {
            mp[idx].second++;
        } else {
            mp[idx] = {it, 1};
        }
    }

    sort(mp.begin(), mp.end(), compare);
    int ans = 0;
    bool oddUsed = false;
for (auto it : mp) {
    if (it.second % 2 == 0) {
        ans += it.second;
    } else {
        ans += it.second - 1;
        oddUsed = true;
    }
}
if (oddUsed) ans += 1;
    return ans;

    }
};
