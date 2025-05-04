/*Number of Equivalent Domino Pairs
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.
Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].
Example 1:
Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1
Example 2:
Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
Output: 3*/
class Solution {
    string convert(vector<int>& temp) {
        string s = "";
        s += to_string(temp[0]);
        s += to_string(temp[1]);
        return s;
    }

public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> mp;
        for (auto it : dominoes) {
            vector<int> temp = {it[0], it[1]};
            sort(temp.begin(), temp.end());
            string s = convert(temp);
            mp[s]++;
        }
        int res = 0;
        for (auto it : mp) {
            if (it.second == 2) {
                res++;
            } else if (it.second > 2) {
                int r = 2;
                int n = it.second;
                int tempp = n * (n - 1) / 2;
                res += tempp;
            }
        }
        return res;
    }
};
