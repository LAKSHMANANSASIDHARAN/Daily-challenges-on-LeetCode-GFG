/*Given an array of strings nums containing n unique binary strings each of length n, return a binary string of
length n that does not appear in nums. If there are multiple answers, you may return any of them.
Example 1:
Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:
Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:
Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.*/
class Solution {
    string finding(set<string>& st, string ans, int n) {
        if (ans.size() == n) {
            if (st.find(ans) == st.end()) {
                return ans;
            }
            return "";
        }
        
        string res = finding(st, ans + "0", n);
        if (!res.empty()) return res;
        
        res = finding(st, ans + "1", n);
        return res;
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st(nums.begin(), nums.end());
        return finding(st, "", nums[0].size());
    }
};
